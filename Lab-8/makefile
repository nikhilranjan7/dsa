compileAll:	tree.o use.o
	gcc -g tree.o use.o -o prog
tree.o: tree.c tree.h
	gcc -c -g tree.c -o tree.o
use.o: use.c tree.h
	gcc -c -g use.c -o use.o
