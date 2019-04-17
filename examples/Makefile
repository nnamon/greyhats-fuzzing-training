all : 1_stack_overflow 2_heap_overflow 3_uninitialized_variables 4_use_after_free 5_double_free 6_type_confusion

1_stack_overflow : 1_stack_overflow.o
	$(CC) -o 1_stack_overflow 1_stack_overflow.o

1_stack_overflow.o :
	$(CC) -c 1_stack_overflow.c

2_heap_overflow : 2_heap_overflow.o
	$(CC) -o 2_heap_overflow 2_heap_overflow.o

2_heap_overflow.o :
	$(CC) -c 2_heap_overflow.c

3_uninitialized_variables : 3_uninitialized_variables.o
	$(CC) -o 3_uninitialized_variables 3_uninitialized_variables.o

3_uninitialized_variables.o :
	$(CC) -c 3_uninitialized_variables.c

4_use_after_free : 4_use_after_free.o
	$(CC) -o 4_use_after_free 4_use_after_free.o

4_use_after_free.o :
	$(CC) -c 4_use_after_free.c

5_double_free : 5_double_free.o
	$(CC) -o 5_double_free 5_double_free.o

5_double_free.o :
	$(CC) -c 5_double_free.c

6_type_confusion : 6_type_confusion.o
	$(CC) -o 6_type_confusion 6_type_confusion.o

6_type_confusion.o :
	$(CC) -c 6_type_confusion.c

clean :
	rm 1_stack_overflow 2_heap_overflow 3_uninitialized_variables 4_use_after_free 5_double_free 6_type_confusion *.o
