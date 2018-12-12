CFLAGS=-Wall -Wpedantic -std=gnu99 -fno-builtin -g
CC= gcc 
LIBS= -lm -lcunit
all: 
    ${CC} ${CFLAGS} demoQuadSolver.c -o qs ${LIBS}
tests:
    ${CC} ${CFLAGS} cunit.c -o test ${LIBS}

