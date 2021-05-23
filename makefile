all:main.c createdata.o LinkedList.o Array.o BinarySearch.o BinarySearchTree.o Hash.o Functions.o
	gcc main.c createdata.o LinkedList.o Array.o BinarySearch.o BinarySearchTree.o Hash.o Functions.o -o a.out
	./a.out
createdata.o:createdata.c createdata.h
	gcc -c createdata.c -o createdata.o
LinkedList.o:LinkedList.c LinkedList.h
	gcc -c LinkedList.c -o LinkedList.o
Array.o:Array.c Array.h
	gcc -c Array.c -o Array.o
Functions.o:Functions.c Functions.h
	gcc -c Functions.c -o Functions.o
BinarySearch.o:BinarySearch.c BinarySearch.h
	gcc -c BinarySearch.c -o BinarySearch.o
BinarySearchTree.o:BinarySearchTree.c BinarySearchTree.h
	gcc -c BinarySearchTree.c -o BinarySearchTree.o
Hash.o:Hash.c Hash.h
	gcc -c Hash.c -o Hash.o 
clean:
	rm -f a.out createdata.o LinkedList.o Array.o BinarySearch.o BinarySearchTree.o Hash.o Functions.o
