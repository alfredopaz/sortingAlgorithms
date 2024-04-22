sorting: sorting.h sorting.o main.o statistics.h statistics.o
	gcc sorting.o main.c statistics.o -o sorting
main.o: sorting.h main.c
	gcc -c main.c
sorting.o: sorting.h sorting.c
	gcc -c sorting.c
statistics.o: statistics.h statistics.c
	gcc -c statistics.c
clean:
	rm *.o sorting
