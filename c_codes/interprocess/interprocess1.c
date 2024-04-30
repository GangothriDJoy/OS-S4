#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    const char *name = "gangu";
    int size = 1000;
    int filedescriptor;
   //printf("\n...\n");
    while ((filedescriptor = shm_open(name, O_RDONLY, 0666)) == -1) {
        printf("Waiting for shared memory object...\n");
        sleep(1);
    }
   //printf("\n...\n");
    printf("Shared memory object detected!\n\n");

    void *ptr = mmap(0, size, PROT_READ, MAP_SHARED, filedescriptor, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    char prev[1000] = "";
    while (1) {
        char current[1000];
        strcpy(current, (char*)ptr);
        if (strcmp(current, prev) != 0) {
            printf("Message: %s\n", current);
            strcpy(prev, current);
        }
    }

    return 0;
}




