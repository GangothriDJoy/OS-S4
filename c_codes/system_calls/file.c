#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void display(const char * filename)
{
        struct stat fileStat;
        if(stat(filename, &fileStat)== -1)
        {
                perror("Error getting the file status!");
                exit(EXIT_FAILURE);
        }
        printf("File: %s\n", filename);
        printf("Size: %lld bytes\n", (long long)fileStat.st_size);
        printf("Mod: %o\n", fileStat.st_mode);
        printf("Last access time: %o\n", ctime(&fileStat.st_atime));
        printf("Last modification time: %o\n", ctime(&fileStat.st_mtime));
        printf("______________________________________________________________________\n");
}

int main()
{
        DIR * directory;//to get the directory data
        struct dirent * entry;
        directory=opendir(".");//to get the current working directory
        if(directory == NULL)// couldn't open the present directory
        {
                perror("Error in opening the current working directory!!");
                exit(EXIT_FAILURE);
        }
        while((entry = readdir(directory))!=NULL)
        {
                if(entry->d_type==DT_REG)
                {
                        display(entry->d_name);
                }
        }
        closedir(directory);
}


