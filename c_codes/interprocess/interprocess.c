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
    int filedescriptor = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (filedescriptor == -1) {
        perror("shm_open");
        exit(1);
    }
    else
    {
        printf("\nshm_open successful\n");
    }
    if (ftruncate(filedescriptor, size) == -1) {
        perror("ftruncate size fixture error");
        exit(1);
    }

    void *ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, filedescriptor, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    char choice;
    do {
        printf("Enter the message to write: ");
        char *string = malloc(100);
        if (string == NULL) {
            perror("malloc error allocating memory");
            exit(1);
        }
        scanf(" %[^\n]", string);
        strcpy(ptr, string);
        free(string);
        printf("Do you wish to continue?(y/n)");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    if (close(filedescriptor) == -1) {
        perror("close");
        exit(1);
    }

    return 0;
}

