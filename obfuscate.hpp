#include <cstddef>
#include <cstdint>

void transpose(const uint32_t* src, uint32_t* dst, size_t M, size_t N) noexcept;

void obfuscate(int64_t*);
void obfuscate(uint64_t*);

void obfuscate(int32_t*);
void obfuscate(uint32_t*);

void obfuscate(int16_t*);
void obfuscate(uint16_t*);

void obfuscate(int8_t*);
void obfuscate(uint8_t*);
