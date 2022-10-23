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
char *readline(){
    int bufsize = 1024;
    int position = 0;
    char *buffer = malloc(sizeof(char)*bufsize);
    int c;

    if(!buffer){ //malloc 오류
        fprintf(stderr, "allocation error");
        exit(0);
    }
    while(1){
        c = getchar();
        if(c==EOF || c =='\n'){ //끝 문자 만났을 때
            for(int i=0;i<strlen(buffer);i++){ //pipe 개수 세기
                if(buffer[i]=='|')
                    pipe_count++;
            }
            buffer[position]='\0';
            return buffer;
        }
        else buffer[position] =c;
        position++;
    }

}