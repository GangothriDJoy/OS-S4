#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
        // creating a new process by calling fork function which returns to a data type pid_t
        pid_t pid;
        pid = fork(); // pid is a variable of type pid_t.it is a data type used for process IDs defined in <sys/types.h>
        /* fork() function creates a child process form the parent process, by duplicating it. both processes continue to execute
           from the point where fork() was called , but they get different return values*/
        // in the child process, pid is set to 0; in the parent process, pid is set to the child's process ID
        if(pid<0)
        {
                //fork is failed if pid<0
                perror("Fork failed");//error messages are printed using perror(), which prints the descrption associated with the
                                      //last error that occured, and the program exists with a failure status
                exit(EXIT_FAILURE);
        }
        else if(pid == 0)
        {
                printf("child process: My PID is %d\n", getpid());//since pid value is 0, we print the child process's ID using getpid()
                printf("child process: My parent's PID is %d\n", getppid());//parent's ID is get using getpid()
                exit(EXIT_SUCCESS);//child process exits with success status
        }
        else if (pid > 0)
        {
                printf("Parent process: My PID is %d\n", getpid());//pid will be the child's PID, so we print the parent's PID using getpid()
                printf("Parent process: My child's PID is %d\n", pid);//child's PID is print using pid
                int status;
                waitpid(pid, &status, 0);//waitpid() is used to wait for the child's process to complete.
                //waitpid() takes the child's PID, a pointer to the integer "status", and the option value set to zero zero for simplicity
                if(WIFEXITED(status))
                {
                        printf("The child exited with exit status %d\n", WIFEXITED(status));
                }
                else
                {
                        printf("The child exited abm=normally!");
                }
        }
}

