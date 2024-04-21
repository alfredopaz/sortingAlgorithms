sorting: sorting.h sorting.o main.c
	gcc sorting.o main.c -o sorting
sorting.o: sorting.h
	gcc -c sorting.c
