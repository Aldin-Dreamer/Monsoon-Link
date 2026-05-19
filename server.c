#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define BUFFSIZE 1024
#define SOCK_PATH "/path" // following man - idk what the path is.
#define BACKLOG 50 // Using the macro in the man example. Confused as to whether the length of backlog refers to the amount of request or 
                   // length of request or length of packet

char buffer[BUFFSIZE];

int main() {
    int server_fd, client_fd; // Server File descriptor
    struct sockaddr_un address; // address for local communication domain - required for binding file descriptor to port
    int addrlen = sizeof(address);
    if ((server_fd = socket(AF_LOCAL,SOCK_STREAM,0))<0)
        exit(EXIT_FAILURE);
    memset(&address, 0, addrlen); //From Linux man page, no idea why though
    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, SOCK_PATH, sizeof(address.sun_path)-1); // Following the man again but have no idea why we are minusing from address size
    if (bind(server_fd,(struct sockaddr *)&address,addrlen)<0)
        exit(EXIT_FAILURE);
    if (listen(server_fd, BACKLOG)<0)
        exit(EXIT_FAILURE);
    if ((client_fd = accept(server_fd,(struct sockaddr *) &address, &addrlen))<0)
        exit(EXIT_FAILURE);
    if(recv(client_fd, buffer, BUFFSIZE, 0)<0)
        exit(EXIT_FAILURE);
    printf("%s", buffer);
    // Do not know what close or unlink here achieves and why we do it
    if (close(server_fd)<0)
        exit(EXIT_FAILURE);
    if (unlink(SOCK_PATH)<0)
        exit(EXIT_FAILURE);
    return 0;
}
/* AF_LOCAL - Local Communication domain
 * SOCK_STREAM - TCP communication
 */

