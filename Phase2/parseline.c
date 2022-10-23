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
int pipe_count;
int pipe_position;
char** parseline(char *line) 
{
    int position =0;
    char **split = malloc(64 * sizeof(char*));
    char **pipe_split1 = malloc(64 * sizeof(char*));
    char **pipe_split2 = malloc(64 * sizeof(char*));
    char *token;
    int arg_count=0;
    
    token =strtok(line," \t\r\n\a\"");
    while(token != NULL){
        if(!strcmp(token, "|")){
           for(int i=0;i<arg_count;i++){
               pipe_split1[i]=split[i];
               pipe_position = arg_count;
           }
        }   
        split[position]=token;
        position++;
        token = strtok(NULL, " \t\r\n\a\"");
        arg_count++;
    }
    pipe_split1[pipe_position]=NULL;
    for(int i=0;i<arg_count - pipe_position;i++){
        pipe_split2[i]=split[i + pipe_position+1];
    }
    pipe_split2[arg_count-pipe_position]=NULL;
    /*pipe_split2[0]= split[2];
    pipe_split2[1]=NULL;*/
    if(pipe_count) pipe_action(pipe_split1, pipe_split2);
    split[position]=NULL;
    return split;
}