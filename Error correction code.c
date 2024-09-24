//Implementing the simulation of error correction code - CRC in C
#include <stdio.h>
#define POLYNOMIAL 0x8005  // CRC-16 polynomial (reverse)
unsigned short crc16(unsigned char *data, unsigned int length) 
{
    unsigned short crc = 0x0000;  // Initial value
    for (unsigned int i = 0; i < length; i++) 
    {
        crc ^= (data[i] << 8);  // XOR byte into high order byte of CRC
        for (unsigned char bit = 0; bit < 8; bit++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ POLYNOMIAL;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}
int main() {
    unsigned char data[] = "123456789";  // Example data
    unsigned int length = sizeof(data) - 1;  // Calculate length of data
    unsigned short result = crc16(data, length);
    printf("CRC16 result: 0x%04X\n", result);
    return 0;
}
Output:
CRC16 result: 0xFEE8
