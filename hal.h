// Hardware Abstraction layer interface
// This header itself is OS dependent but the implementation will vary with the OS
#ifndef HAL_H
#define HAL_H

// socket_init - Initializes the communication interface. Returns 0 on success, -1 on failure
int socket_init(int );
int hal_send();
int hal_recv();
int hal_close();

#endif
