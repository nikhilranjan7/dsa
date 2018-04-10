gcc -c implement.c -o implement.o
gcc -c file.c -o file.o
gcc -c use.c -o use.o
gcc implement.o file.o use.o -o prog
./prog
