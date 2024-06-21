// File: crc.cppm
export module crc;

#include <vector>
#include <bitset>
#include <cstdint>

export namespace crc {
    constexpr uint32_t CRC32_POLYNOMIAL = 0xEDB88320;

    // Function to initialize CRC32
    export std::bitset<32> initializeCRC32() {
        return std::bitset<32>(0xFFFFFFFF);
    }

    // Function to update CRC32 with a byte of data
    export std::bitset<32> updateCRC32(std::bitset<32> crc, uint8_t byte) {
        crc ^= std::bitset<32>(byte);
        for (size_t j = 0; j < 8; ++j) {
            if (crc[0]) {
                crc = (crc >> 1) ^ std::bitset<32>(CRC32_POLYNOMIAL);
            }
            else {
                crc >>= 1;
            }
        }
        return crc;
    }

    // Function to finalize CRC32 calculation
    export std::bitset<32> finalizeCRC32(std::bitset<32> crc) {
        return crc ^ std::bitset<32>(0xFFFFFFFF);
    }

    // Function to calculate CRC32 checksum for a given data array
    export std::bitset<32> calculateCRC32(const uint8_t* data, size_t size) {
        std::bitset<32> crc = initializeCRC32();

        for (size_t i = 0; i < size; ++i) {
            crc = updateCRC32(crc, data[i]);
        }

        return finalizeCRC32(crc);
    }
}
