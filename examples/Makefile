all : 1_stack_overflow 2_heap_overflow

1_stack_overflow : 1_stack_overflow.o
	$(CC) -o 1_stack_overflow 1_stack_overflow.o

1_stack_overflow.o :
	$(CC) -c 1_stack_overflow.c

2_heap_overflow : 2_heap_overflow.o
	$(CC) -o 2_heap_overflow 2_heap_overflow.o

2_heap_overflow.o :
	$(CC) -c 2_heap_overflow.c

clean :
	rm 1_stack_overflow 2_heap_overflow *.o
