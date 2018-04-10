gcc -c -g graph.c -o graph.o
gcc -c -g driver.c -o driver.o
gcc -g graph.o driver.o -o prog
./prog
