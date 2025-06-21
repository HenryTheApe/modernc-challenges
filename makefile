CFLAGS = -std=c11 -ggdb3 -Wall -Wpedantic -Og
OPT_MACROS = -DDEBUG_MSG_ON
CC=gcc
LIBS = -lm

1-SequentialSortingAlgorithms:
	gcc $(CFLAGS) -o $@ 1-SequentialSortingAlgorithms.c

2-NumericalDerivatives:
	gcc $(CFLAGS) -o $@ 2-NumericalDerivatives.c $(LIBS)

3-PiDigits:
	gcc $(CFLAGS) -o $@ 3-PiDigits.c

