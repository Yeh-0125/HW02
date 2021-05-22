#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"Array.h"
#include"Functions.h"

void arraysearch(int *data,char *str){
	int apple=atoi(str);
	while(*data){
		if(*data==apple){
			printf("ある！\n");
			return;
		}
		data++;
	}
	//printf("ない！\n");
}

void Array(int dataCnt){
	struct  timeval start;
    struct  timeval end;
    unsigned  long diff=0;
    int data[dataCnt];
	int i=0;
    FILE *file;
    char *str=(char *)malloc(128*sizeof(char));
    file=fopen("dataset1.txt","r");

    printf("Array:\n");
    gettimeofday(&start,NULL);
    while(fgets(str,128,file)!=NULL){
        renewline(str);
        data[i]=atoi(str);
		i++;
    }
    fclose(file);
    
	gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("building time: %ld microsec\n",diff);
    
	gettimeofday(&start,NULL);
    file=fopen("dataset2.txt","r");
    while(fgets(str,128,file)!=NULL){
        renewline(str);
        arraysearch(data,str);
    }
    
	fclose(file);
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("query time: %ld microsec\n\n",diff);	
}
/*
    void search(int *data,char *str);
	void Array(int dataCnt);
	*/
