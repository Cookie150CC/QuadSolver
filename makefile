# Grant Gannon, Brittain Cooke, Oliver Sanchez
# Senior Design 2018-2019

CFLAGS=-Wall -Wpedantic -std=gnu99 -fno-builtin -g
CC= gcc
LIBS= -lm -lcunit
all: 
	${CC} ${CFLAGS} demoQuadSolver.c -o qs ${LIBS}
tests:
	${CC} ${CFLAGS} cunit.c -o test ${LIBS}
