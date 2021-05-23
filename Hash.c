#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"Functions.h"
#include"Hash.h"

unsigned int hash65(char *key){
    unsigned int hv=0;
    char *ptr;

    ptr=key;
    while(*ptr){
        hv=hv * 65 + *ptr;
        ptr++;
    }
    return hv;
}

hNode *list_insert(hNode *ptr,char *str){
	hNode *qtr=ptr;
	if(!ptr){
		ptr=(hNode *)malloc(sizeof(hNode));
		ptr->apple=atoi(str);
		ptr->next=NULL;
		return ptr;
	}
	
	while(ptr->next){
        ptr=ptr->next;
    }
	hNode *bptr=(hNode *)malloc(sizeof(hNode));
    bptr->apple=atoi(str);
    bptr->next=NULL;
	ptr->next=bptr;
	return qtr;
}

void hash_insert(hNode** hashTable,char *str){
	unsigned int hv=0;
	hv=hash65(str)%32768;
	//printf("%s\n",str);
	hNode *ptr=hashTable[hv];
	hashTable[hv]=list_insert(ptr,str);
}

void list_find(hNode *ptr,char *str){
    while(ptr){
		if(ptr->apple==atoi(str)){
			printf("ある！\n");
		}
		ptr=ptr->next;
	}
}

void hash_find(hNode** hashTable,char *str){
    unsigned int hv=0;
    hv=hash65(str)%32768;
    //printf("%s\n",str);
    hNode *ptr=hashTable[hv];
    list_find(ptr,str);
}

void hprint(hNode **hashTable){
	printf("==========\n");
	for(int i=0;i<32768;i++){
		if(hashTable[i]!=NULL){
			hNode *ptr=hashTable[i];
			while(ptr){
				printf("%d ",ptr->apple);
				ptr=ptr->next;
			}
			printf("\n");
		}
	}
	printf("==========\n");
}

void Hash(){
	struct  timeval start;
    struct  timeval end;
    unsigned  long diff=0;
	//建立HashTable
	hNode **hashTable;
	int maxHash=32768;
	hashTable=(hNode **)malloc(maxHash * sizeof(hNode *));
	for(int i=0;i<maxHash;i++){
		hashTable[i]=NULL;
	}
	
	char *str=(char *)malloc(128 * sizeof(char));
	FILE *file;
	file=fopen("dataset1.txt","r");

	printf("Hash:\n");
    gettimeofday(&start,NULL);
	while(fgets(str,128,file)!=NULL){
		renewline(str);
		hash_insert(hashTable,str);
	}
	fclose(file);
	//hprint(hashTable);
	gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("building time: %ld microsec\n",diff);
    
	gettimeofday(&start,NULL);
	file=fopen("dataset2.txt","r");
	while(fgets(str,128,file)!=NULL){
        renewline(str);
        hash_find(hashTable,str);
    }
	fclose(file);
	gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("query time: %ld microsec\n\n",diff);
}
