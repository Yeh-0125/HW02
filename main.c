#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"createdata.h"
#include"LinkedList.h"
#include"Array.h"
#include"BinarySearch.h"
#include"BinarySearchTree.h"

int main(){
	int dataCnt1=100000;
	int dataCnt2=100000;
	createdata(dataCnt1,dataCnt2);

	LinkedList();
	Array(dataCnt1);
	BinarySearch(dataCnt1);
	BinarySearchTree();
	//Hash();

	return 0;
}
