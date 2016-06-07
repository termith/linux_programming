#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(int argc, char const *argv[])
{
        pid_t pid, sid;
        
        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                exit(EXIT_SUCCESS);
        }    
        
        
        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log any failure here */
                exit(EXIT_FAILURE);
        }
        
        /* Change the current working directory */
        if ((chdir("/")) < 0) {
                /* Log any failure here */
                exit(EXIT_FAILURE);
        }
        printf("%d\n", sid);
        
        
        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        while (1) {}
    return 0;
}