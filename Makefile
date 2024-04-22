sorting: sorting.h sorting.o main.o
	gcc sorting.o main.c -o sorting
main.o: sorting.h main.c
	gcc -c main.c
sorting.o: sorting.h sorting.c
	gcc -c sorting.c
clean:
	rm *.o sorting
