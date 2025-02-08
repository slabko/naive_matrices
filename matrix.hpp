#include <cstddef>
namespace mtx
{

template<typename T>
void transpose(
    const T* src, 
    T* dst, 
    // size of the whole destination matrix
    const size_t stride_src, 
    const size_t stride_dst,
    // size of the sub-matrix
    const size_t M, 
    const size_t N,
    // offset of the sub-matrix
    const size_t I, 
    const size_t J 
) noexcept {
    for (size_t j = 0; j < N; ++j) {
        for (size_t i = 0; i < M; ++i) {
            dst[(stride_dst*(j+J)) + i + I] = src[(stride_src*(i + I)) + j + J];
        }
    }
}

template<typename T>
void transpose(const T* src, T* dst, size_t M, size_t N) noexcept {
    const size_t block_size = 128;
    const size_t m_blocks = M / block_size;
    const size_t n_blocks = N / block_size;

    for (size_t j = 0; j < n_blocks; ++j) {
        for (size_t i = 0; i < m_blocks; ++i) {
            transpose<T>(src, dst, N, M, block_size, block_size, i * block_size, j * block_size);
        }
    }

    for (size_t j = 0; j < m_blocks; ++j) {
        transpose<T>(
            src, dst, 
            N, M, 
            block_size, N - (n_blocks * block_size), 
            j * block_size, n_blocks * block_size);
    }

    transpose<T>(
        src, dst, 
        N, M, 
        M - (m_blocks * block_size), N - (n_blocks * block_size), 
        m_blocks * block_size, n_blocks * block_size);

    for (size_t i = 0; i < n_blocks; ++i) {
        transpose<T>(
            src, dst, 
            N, M, 
            M - (m_blocks * block_size), block_size, 
            m_blocks * block_size, i * block_size);
    }
}

} // namespace mtx
