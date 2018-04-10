compileAll:	implement.o	file.o use.o
	gcc implement.o file.o use.o -o prog
implement.o: implement.c implement.h
	gcc -c implement.c -o implement.o
file.o: file.c implement.h
	gcc -c file.c -o file.o
use.o: use.c implement.h
	gcc -c use.c implement.h
