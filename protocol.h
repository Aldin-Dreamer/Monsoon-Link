// OS Independent functions

/* Packet Layout
 * | SYNC1 | SYNC2 | Type | 
 */
#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

/*************MACROS*************/

#define SYNC1 0xAA
#define SYNC2 0x55
#define MAX_PACKET_SIZE 32
#define HEADER_SIZE 6

/***********FUNCTIONS************/

uint8_t crc8();
uint16_t crc16();

#endif
