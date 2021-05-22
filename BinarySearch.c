#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"BinarySearch.h"
#include"Functions.h"

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

void BinarySearch(int dataCnt){
	struct  timeval start;
    struct  timeval end;
    unsigned  long diff=0;
    int data[dataCnt];
	int i=0;
    FILE *file;
    char *str=(char *)malloc(128*sizeof(char));
    file=fopen("dataset1.txt","r");

    printf("BinarySearch:\n");
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
    
	qsort(data,dataCnt,sizeof(int),cmpfunc);

	gettimeofday(&start,NULL);
    file=fopen("dataset2.txt","r");
	int apple=0;
    while(fgets(str,128,file)!=NULL){
        renewline(str);
		apple=atoi(str);
		if(bsearch(&apple,data,dataCnt,sizeof(int),cmpfunc)==NULL){
			//printf("ない！\n");
		}
		else{
			printf("ある！\n");
		}
    }
    
	fclose(file);
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("query time: %ld microsec\n\n",diff);	
}
