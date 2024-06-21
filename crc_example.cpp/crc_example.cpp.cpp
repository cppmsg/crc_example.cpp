// crc_example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import crc;
import std;

int main()
{
    std::vector<std::uint8_t> data = { 0x01, 0x02, 0x03, 0x04, 0x05 }; // Example data
    size_t dataSize = data.size();

    // Calculate CRC32 checksum
    std::bitset<32> crcResult = crc::calculateCRC32(data.data(), dataSize);

    // Output the CRC32 checksum in binary format
    std::cout << "CRC32 checksum (binary): " << crcResult << std::endl;

    return 0;
}

//g++ - std = c++20 - fmodules - ts crc.cppm main.cpp - o crc_example
//. / crc_example
