#include <cassert>
#include <iostream>
#include <numeric>
#include <chrono>
#include <format>
#include "obfuscate.hpp"

namespace {
constexpr size_t M = (1024UL * 16) + 2;
constexpr size_t N = (1024UL * 16) + 2;
} // anonymous namespace

int main()
{
    auto* src = new uint32_t[M * N];
    std::iota(src, src + (M * N), 0);
    auto* dst = new uint32_t[M * N];
    std::fill(dst, dst + (M * N), 0);

    auto start = std::chrono::steady_clock::now();

    for (size_t i = 0; i < 8; ++i) {
        transpose(src, dst, M, N);
        obfuscate(dst);
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::format("Wall time: {}\n", diff);
 
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            assert(src[(j * N) + i] == dst[(i * M) + j]);
        }
    }

}
