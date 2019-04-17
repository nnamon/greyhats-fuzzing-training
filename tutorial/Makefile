all : main

main : main.o vulnerable.o
	$(CC) -g -o main main.o vulnerable.o

main.o :
	$(CC) -g -c main.c

vulnerable.o :
	$(CC) -g -c vulnerable.c

clean :
	rm main *.o
