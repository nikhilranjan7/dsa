gcc -g -c lab.c -o lab.o
gcc -g -c drive.c -o drive.o
gcc -g lab.o drive.o -o prog
./prog
