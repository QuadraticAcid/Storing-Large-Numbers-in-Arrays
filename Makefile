CC = gcc
objects = main.o addition.o division.o factorial.o mem.o multiplication.o subtraction.o

main: $(objects)
	$(CC) -o main $(objects) -lm

main.o: main.c addition.c addition.h division.c division.h factorial.c factorial.h mem.c mem.h multiplication.c multiplication.h \
	subtraction.c subtraction.h structure.h
	$(CC) -c main.c

addition.o: addition.c addition.h structure.h
	$(CC) -c addition.c

division.o: addition.c addition.h division.c division.h mem.c mem.h multiplication.c multiplication.h subtraction.c subtraction.h \
	structure.h
	$(CC) -c division.c

factorial.o: addition.c addition.h factorial.c factorial.h mem.c mem.h multiplication.c multiplication.h subtraction.c subtraction.h structure.h
	$(CC) -c factorial.c

mem.o: mem.c mem.h
	$(CC) -c mem.c

multiplication.o: mem.c mem.h multiplciation.c multiplication.h structure.h
	$(CC) -c multiplication.c

subtraction.o: subtraction.c subtraction.h structure.h
	$(CC) -c subtraction.c

clean:
	rm main $(objects)
