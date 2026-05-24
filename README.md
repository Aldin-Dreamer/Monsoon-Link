<div align="center">

## Packet Structure

This communication layer uses a fixed size header to each packets. The layput is:
```
| Sync(2 bytes) | Type(1 byte) | Sequence(1 byte) | Length(1 byte) | Header CRC8(1 byte) | Data Payload (max: 24 bytes) | Data CRC16 (2 bytes) |
```
</div>

**Sync —** Magic number to signify the start of the packet frame. 
**Type —** ```ACK``` to send back to the sender so that if it isnt recieved the sender retransmits the packet. ```NACK``` to send back to the sender if a packet is corruped and needs a retransmission. ```DATA``` to signify this packet contains data payload.
**Sequence —** Each packet is assigned a sequence number to identify dropped packets during transmission.
**Length —** Contains the length of the data payload for allowing variable length packets.
**Header CRC8 —** CRC8 is used for error detection in the header.
**Data Payload —** The data being sent.
**Data CRC16 —** CRC16 is used to check for the error detection of the data.

## Acknowledgements
- [Wikipedia Article for CRC](https://en.wikipedia.org/wiki/Cyclic_redundancy_check#Computation)
- [A Painless Guide to CRC Error Detection Algorithms by Ross N. Williams](https://web.archive.org/web/20180402205812/http://www.wolfgang-ehrhardt.de/crc_v3.html#chap_07)

