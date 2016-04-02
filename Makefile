CC = gcc
CFLAGS = -I.

DEPS = CHStack.h
OBJ = CHStack.o CHStackPeekTests.o AllTests.o CuTest.o CuTestTest.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stackTests: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ 