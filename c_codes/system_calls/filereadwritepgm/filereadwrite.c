#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
        int filedescriptor;
        char data[BUFFER_SIZE];
        char buffer[BUFFER_SIZE];

        if((filedescriptor = open("EXAMPLE>TXT", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR)==-1))
        {
                perror("Cant open file or file does not exist!");
                exit(EXIT_FAILURE);
        }
        printf("Enter the data to be stored: ");
        scanf(" %s", data);
        //printf("Enter the data to be wrote to the file: ");
        //fgets(data, sizeof(data), stdin);
        write(filedescriptor, data, strlen(data));
        lseek(filedescriptor, 0, SEEK_SET);
        ssize_t bytesread=read(filedescriptor, buffer, sizeof(buffer));
        printf("Read from file: %s\n", /*(int)bytesread,*/ buffer);
        close(filedescriptor);
        return 0;
}


