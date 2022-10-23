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
char** parseline(char *line) 
{
    int position =0;
    char **split = malloc(64 * sizeof(char*));
    char *token;
    
    token =strtok(line," \t\r\n\a\"");
    while(token != NULL){
        split[position]=token;
        position++;
        token = strtok(NULL, " \t\r\n\a\"");
    }
    split[position]=NULL;
    return split;
}