#include"myshell.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    char*cmdline;

    while (1) {
	printf("> ");                   
    cmdline = readline(); //��ɾ� �б�
	if (feof(stdin))
	    exit(0);

	eval(cmdline); //��ɾ� ����
    } 
}
