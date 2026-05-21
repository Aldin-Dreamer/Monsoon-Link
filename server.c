#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
//#include <sys/un.h>

//#define SOCK_PATH "/path" 
#define BUFFSIZE 1024
#define PORT 60000 // For TCP any port between 49152-65535
#define BACKLOG 2 

char buffer[BUFFSIZE];

int main() {
    int server_fd, client_fd; // Server File descriptor
    //struct sockaddr_un address; // address for local communication domain - required for binding file descriptor to port
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    if ((server_fd = socket(AF_INET,SOCK_STREAM,0))<0)
        exit(EXIT_FAILURE);
    memset(&address, 0, addrlen); 
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    //strncpy(address.sun_path, SOCK_PATH, sizeof(address.sun_path)-1);
    if (bind(server_fd,(struct sockaddr *)&address,addrlen)<0)
        exit(EXIT_FAILURE);
    if (listen(server_fd, BACKLOG)<0)
        exit(EXIT_FAILURE);
    if ((client_fd = accept(server_fd,(struct sockaddr *) &address, &addrlen))<0)
        exit(EXIT_FAILURE);
    if(recv(client_fd, buffer, BUFFSIZE, 0)<0)
        exit(EXIT_FAILURE);
    printf("%s", buffer);
    if (close(client_fd) < 0)
        exit(EXIT_FAILURE);
    if (close(server_fd)<0)
        exit(EXIT_FAILURE);
    //if (unlink(SO`CK_PATH)<0)
    //    exit(EXIT_FAILURE);
    return 0;
}
/* AF_LOCAL - Local Communication domain
 * SOCK_STREAM - TCP communication
 */

