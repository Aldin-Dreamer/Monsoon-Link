// Linux specific implentation of OS-dependent functions in hal.h

#include "hal.h"
#include <sys/socket.h>
#include <sys/un.h>

int socket_init(int domain, int type, int protocol){
    int fd = socket(domain, type, protocol);
    return fd;
}

