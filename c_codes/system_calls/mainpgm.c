
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
        printf("\n");
        pid_t pid;
        pid = fork();
        if(pid < 0)
        {
                perror("Child process creation failed!");
                exit(EXIT_FAILURE);
        }
        else if(pid == 0)
        {
                execlp("./summed", "summed", NULL);
        }
        else if(pid >0)
        {
                printf("I'm a poor parent waiting for my child to complete his process\n");
                int status;
                waitpid(pid, &status, 0);
                if(WIFEXITED(status))
                {
                        printf("YEAH!My child completed his process successfully\n\n!!!");
                }
                else
                {
                        printf("My child didn't do it..infact I couldn't wait for him to complete his damn process\n\n!");
                }
        }
        return 0;
}




