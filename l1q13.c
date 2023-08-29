#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;

    // Watch STDIN (file descriptor 0) to see when it has input.
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    // Set the timeout to 10 seconds.
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input from STDIN for 10 seconds...\n");

    // Wait for input or timeout using select.
    retval = select(1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select");
    } else if (retval) {
        if (FD_ISSET(0, &rfds)) {
            printf("Data is available now!\n");
        }
    } else {
        printf("No data within 10 seconds.\n");
    }

    return 0;
}
