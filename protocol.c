#include "protocol.h"

/* Purpose: To compute the CRC-8 of given data
 * Polynomial: 0x07 (Standard CRC8 polynomial)
 * INPUT: The pointer to the beginning of data and the length of the data
 * OUTPUT: Returns the CRC remainder
 * Stack Size: Return address - 2 bytes (depends on the architecture)
 *             parameters - 2 bytes
 *             Base pointer register - 2 bytes (depends on the architecture)
 *             local variables - 3 bytes
 *             Total - 9 bytes
 */
uint8_t crc8(uint8_t *data, uint8_t len){
    uint8_t crc = 0xFF; // 0xFF chosen to eliminate blindness of leading zeroes.
    for (uint8_t i=0;i<len;i++){
        crc ^= data[i];
        for (uint8_t j=0;j<8;j++){
            crc = (crc & 0x80) ? (uint8_t)((crc << 1) ^ 0x07) : (uint8_t)(crc << 1);
        }
    }
    return crc;
}

/* Purpose: To compute the CRC-16 of given data
 * Polynomial: 0x1021 (Standard CRC-16 Polynomial)
 * INPUT: The pointer to the beginning of data and the length of the data
 * OUTPUT: Returns the CRC remainder
 * Stack Size: Return address - 2 bytes (depends on the architecture)
 *             parameters - 2 bytes
 *             Base pointer register - 2 bytes (depends on the architecture)
 *             local variables - 4 bytes
 *             Total - 10 bytes
 */
uint16_t crc16(uint8_t *data, uint8_t len){
    uint16_t crc = 0xFFFF // 0xFF chosen to eliminate blindness of leading zeroes.
    for (uint8_t i=0;i<len;i++){
        crc ^= (uint16_t)data[i] << 8;
        for (uint8_t j=0;j<16;j++)
            crc = (crc & 0x8000) ? (uint16_t)((crc << 1) ^ 0x1021) : (uint16_t)(crc << 1);
    }
    return crc;
}
