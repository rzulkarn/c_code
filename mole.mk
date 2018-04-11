
CC=gcc
CFLAGS=-g

mole.o: mole.c
	${CC} ${CFLAGS} -c mole.c

mole: mole.o
	${CC} ${CFLAGS} -o mole mole.o

all: mole

clean:
	\rm -rf *.o mole a.out\*
