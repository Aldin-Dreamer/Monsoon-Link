#include <stdio.h> // FOR TESTING PURPOSE
#include <stdint.h>
#include "protocol.h"
#include "channel.h"

int main(int argc, char *argv[]) {
    if (argc < 3){
        printf("Usage: %s <port>\n", argv[0]); // For testing
        return 1;
    }
    
    return 0;
}
