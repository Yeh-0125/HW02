#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"Functions.h"
#include"LinkedList.h"

Node *insert(Node *top,char *str){
	Node *new_node=(Node *)malloc(sizeof(Node));
	new_node->apple=atoi(str);

	new_node->next=top;
	return new_node;
}

void print(Node *top){
	Node *ptr=top;
	for(int i=0;i<5;i++){
		printf("%d\n",ptr->apple);
		ptr=ptr->next;
	}
}

void search(Node *top,char *str){
	int apple=atoi(str);
	Node *ptr=top;

	while(ptr){
		if(ptr->apple==apple){
			printf("ある！\n");
			return;
		}
		ptr=ptr->next;
	}
	//printf("ない！\n");
}

void LinkedList(){
	struct  timeval start;
    struct  timeval end;
    unsigned  long diff=0;
	Node *top=NULL;
	FILE *file;
	char *str=(char *)malloc(128*sizeof(char));
	file=fopen("dataset1.txt","r");
	printf("LinkedList:\n");
	gettimeofday(&start,NULL);
	while(fgets(str,128,file)!=NULL){
		renewline(str);
		top=insert(top,str);
	}
	fclose(file);
	gettimeofday(&end,NULL);
	diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("building time: %ld microsec\n",diff);	
	gettimeofday(&start,NULL);
	file=fopen("dataset2.txt","r");
	while(fgets(str,128,file)!=NULL){
		renewline(str);
		search(top,str);
	}
	fclose(file);
	gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("query time: %ld microsec\n\n",diff);
}

