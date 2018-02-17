gcc -c que.c -o que.o
gcc -c driver.c -o driver.o
gcc -c multiq.c -o multiq.o
gcc -c file.c -o file.o
gcc que.o multiq.o driver.o file.o -o prog
./prog
