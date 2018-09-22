exec:	main.o intSet.o random.o benchmark.o hash.o
	gcc main.o hash.o intSet.o random.o benchmark.o -o exec

main.o:	main.c
	gcc -c main.c

intSet.o:	intSet.c	intSet.h
	gcc -c intSet.c

random.o:	random.c	random.h
	gcc -c random.c

hash.o:		hash.c    hash.h
	gcc -c hash.c

benchmark.o:	benchmark.c	benchmark.h
	gcc -c benchmark.c

clean:
	rm *.o
