#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"createdata.h"
#include"LinkedList.h"
#include"Array.h"
#include"BinarySearch.h"
#include"BinarySearchTree.h"
#include"Hash.h"

int main(int argc,char *argv[]){
	int Cnt=0;
	int dataCnt1=1;
    int dataCnt2=1;
	if(strcmp(argv[1],"-d")==0){
		Cnt=argv[2][2]-'0';
		//printf("Cnt=%d\n",Cnt);
		for(int i=0;i<Cnt;i++){
			dataCnt1=dataCnt1*10;
		}

		Cnt=argv[4][2]-'0';
		//printf("Cnt=%d\n",Cnt);
		for(int i=0;i<Cnt;i++){
            dataCnt2=dataCnt2*10;
        }
	}
	else if(strcmp(argv[1],"-q")==0){
		Cnt=argv[2][2]-'0';
        for(int i=0;i<Cnt;i++){
            dataCnt2=dataCnt2*10;
        }

        Cnt=argv[4][2]-'0';
        for(int i=0;i<Cnt;i++){
            dataCnt1=dataCnt1*10;
        }
    }
	else{
		printf("commend error\n");
	}
	//printf("dataCnt1=%d\n",dataCnt1);
	//printf("dataCnt2=%d\n",dataCnt2);
	createdata(dataCnt1,dataCnt2);
	
	int j=5;

	while(argv[j]){
		if(strcmp(argv[j],"ll")==0){
			LinkedList();
		}
		else if(strcmp(argv[j],"arr")==0){
			Array(dataCnt1);
		}
		else if(strcmp(argv[j],"bs")==0){
			BinarySearch(dataCnt1);
        }
		else if(strcmp(argv[j],"bst")==0){
			BinarySearchTree();
        }
		else if(strcmp(argv[j],"hash")==0){
			Hash();
        }
		else{
			printf("commend error\n");
		}
		j++;
	}
	/*
	LinkedList();
	Array(dataCnt1);
	BinarySearch(dataCnt1);
	BinarySearchTree();
	Hash();*/

	return 0;
}
