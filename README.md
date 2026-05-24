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

The reasoning for this packet structure is:

- The main reason as to why each header parameter is atleast 1 byte is for the ease of writing the code and its harder to code with bits than bytes. I reasoned that if it was needed we could always modify the code later if memory was ever an issue.
- We need a magic number to represent where a packet starts so that the recieving station can parse the packet correctly even if packets are merged. Since the communication channel can modify bytes, a 2 byte magic number is used to reduce errors.
- The Type header is mainly for retransmission incase packets are corrupted or lost during transmission
- The sequence header solves the problem where a communication channel drops random packet, so if the recieving station detects a gap in the sequence, it can send a retransmission request to the sender.
- Length header allows us to use variable length packets which saves bandwidth and memory.
- The use of seperate CRC for header and data is to avoid worst case scenarios. If there was only a single CRC for the whole packet and the length field got corrupted to a large value then it can cause memory to be filled and load the next packet content. In this scenario, the CRC will fail but we will also drop the next packet. So by doing a CRC on a fixed size header we can catch any errrors in the header beforehand.
- I used the more accurate CRC-16 for the data since there is a higher likelihood of errors in data than header.

## File Structure

- **protocol.h —** The header file with all the function declaration of OS-independent functions and structures
- **protocol.c —** The implementations of functions defined in protocol.h
- **hal.h —** Header file that acts as a hardware abstraction layer. This contains all the declaration of OS-dependent function and structure so that the code can be tested in linux and can be ported to other systems easily. The header file itself is OS-independent but the implementation can wary.
- **linux-hal.c —** The Linux-specific implementation of the OS-dependent functions defined in hal.h
- **device.c —** The main deliverable for this task. This is the final code that is run on the machine.
- **server.c —** This was a practice code to learn basic socket programming and function calls.

## Acknowledgements
- [Wikipedia Article for CRC](https://en.wikipedia.org/wiki/Cyclic_redundancy_check#Computation)
- [A Painless Guide to CRC Error Detection Algorithms by Ross N. Williams](https://web.archive.org/web/20180402205812/http://www.wolfgang-ehrhardt.de/crc_v3.html#chap_07)
- Linux man page
