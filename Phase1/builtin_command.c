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
int builtin_command(char **argv) 
{
    if (!strcmp(argv[0], "exit")) /* exit command */
	exit(0);  
    if(!strcmp(argv[0], "cd")){ //cd command
        if(chdir(argv[1])==-1){
            fprintf(stderr, "path error\n");
            return 0;
        }
        return 0;
    }
	return 1;
}