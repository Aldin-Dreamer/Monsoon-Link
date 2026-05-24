#include "protocol.h"

/* Purpose: To compute the CRC of given data
 * Polynomial: 0x07 (Standard CRC8 polynomial)
 * INPUT: The pointer to the beginning of data and the length of the data
 * OUTPUT: Returns the CRC remainder
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

