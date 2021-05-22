#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"Functions.h"

void renewline(char *str){
    while(*str){
        if(*str=='\n'){
            *str='\0';
        }
        str++;
    }
}
