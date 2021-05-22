#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"createdata.h"

int repeat(int *data,int apple,int j){
	if(j==0){
		return 1;
	}
	for(int i=0;i<j;i++){
		if(data[i]==apple){
			return 0;
		}
	}
	return 1;
}

void createdata(int dataCnt1,int dataCnt2){
    int apple;
    int i=0,j=0;
	int data[dataCnt1];
    FILE *file;
    file=fopen("dataset1.txt","w");
	srand(time(NULL));

    for(i=0;i<dataCnt1;i++){
        apple=rand();
		if(repeat(data,apple,j)!=0){
			data[j]=apple;
			j++;
			fprintf(file,"%d\n",apple);
		}
        //printf("%d=%d\n",i,apple[i]);
    }
    fclose(file);

	file=fopen("dataset2.txt","w");
    for(i=0;i<dataCnt2;i++){
        apple=rand();
        fprintf(file,"%d\n",apple);
        //printf("%d=%d\n",i,apple[i]);
    }
    fclose(file);
}
