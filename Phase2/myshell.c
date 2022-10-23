#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myshell.h"
int pipe_count;
int pipe_position;
int main(int argc, char* argv[]){
    char*cmdline;

    while (1) {
	printf("> ");                   
    cmdline = readline(); //명령어 읽기
	if (feof(stdin))
	    exit(0);

	eval(cmdline); //명령어 실행
    } 
}
