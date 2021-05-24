#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"Functions.h"
#include"BinarySearchTree.h"

Leaf * Rinsert(Leaf *root,char *str){
	Leaf *new_leaf=(Leaf *)malloc(sizeof(Leaf));
    new_leaf->apple=atoi(str);
    new_leaf->left=NULL;
    new_leaf->right=NULL;

    if(!root){
        root=new_leaf;
        return root;
    }
    Leaf *ptr=root;
    while(root){
        if(root->apple>atoi(str)){
            if(root->left){
                root=root->left;
            }
            else{
                root->left=new_leaf;
                break;
            }
        }
        else{
            if(root->right){
                root=root->right;
            }
            else{
                root->right=new_leaf;
                break;
            }
        }
    }
    return ptr;
}

void BSTsearch(Leaf *ptr,char *str){
	Leaf *root=ptr;
    while(root){
		if(root->apple==atoi(str)){
			//printf("ある！\n");
			break;
		}
		else if(root->apple>atoi(str)){
            if(root->left){
                root=root->left;
            }
            else{
                //printf("ない！\n");
                break;
            }
        }
        else{
            if(root->right){
                root=root->right;
            }
            else{
                //printf("ない！\n");
                break;
            }
        }
    }
}

void BinarySearchTree(){
	struct  timeval start;
    struct  timeval end;
    unsigned  long diff=0;
	Leaf *root=NULL;
	FILE *file;
	char *str=(char *)malloc(128*sizeof(char));
	file=fopen("dataset1.txt","r");

	printf("BinarySearchTree:\n");
	gettimeofday(&start,NULL);
	while(fgets(str,128,file)!=NULL){
		renewline(str);
		root=Rinsert(root,str);
	}
	fclose(file);
	gettimeofday(&end,NULL);
	diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("building time: %ld microsec\n",diff);

	gettimeofday(&start,NULL);
	file=fopen("dataset2.txt","r");
	while(fgets(str,128,file)!=NULL){
		renewline(str);
		BSTsearch(root,str);
	}
	fclose(file);
	gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("query time: %ld microsec\n\n",diff);
}
