#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
void pipe_action(char ** pipe_split1, char ** pipe_split2){
    int fd[2];
    if(pipe(fd)==-1){
        perror("error");
        exit(0);
    }
    if(fork()==0){
        close(STDOUT_FILENO);
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execvp(pipe_split1[0], pipe_split1);
        exit(0);
    }
    if(fork() == 0) {           
        close(STDIN_FILENO); 
        dup2(fd[0], 0);      
        close(fd[1]);  
        close(fd[0]);

        execvp(pipe_split2[0], pipe_split2);
        exit(0);
    }

    close(fd[0]);
    close(fd[1]);
    wait(0);
    wait(0);
}