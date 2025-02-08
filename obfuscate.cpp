#include "obfuscate.hpp"
#include "matrix.hpp"


void transpose(const uint32_t* __restrict__ src, uint32_t* __restrict__ dst, size_t M, size_t N) noexcept 
{
    mtx::transpose<uint32_t>(src, dst, M, N);
}

void obfuscate(int64_t* /*p*/){}
void obfuscate(uint64_t* /*p*/){}

void obfuscate(int32_t* /*p*/){}
void obfuscate(uint32_t* /*p*/){}

void obfuscate(int16_t* /*p*/){}
void obfuscate(uint16_t* /*p*/){}

void obfuscate(int8_t* /*p*/){}
void obfuscate(uint8_t* /*p*/){}
