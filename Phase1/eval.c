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
void eval(char *cmdline) 
{
    char **argv; 
    int status;           
    pid_t pid, wpid;
    
    argv = parseline(cmdline);  //명령어 쪼개기
    if (argv[0] == NULL)  
	    return;   /* Ignore empty lines */
    if(builtin_command(argv)){  //true이면 builtin이 아님   
        pid = fork();
        if(pid ==0){
            if (execvp(argv[0], argv) < 0) {	//ex) /bin/ls ls -al &
            printf("%s: Command not found.\n", argv[0]);
            exit(0);
        }
        else{
            if(execvp(argv[0], argv)==-1){
                perror("error");
            }    
            exit(0);
        }
    }
        if((wpid = waitpid(pid, &status, 0))<0){
            fprintf(stderr, "waitpid error");
        }
    }
    return;
}