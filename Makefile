CC = gcc
CFLAGS = -I.

DEPS = CHLinkedList.h CHStack.h
OBJ = CHLinkedList.o CHStack.o CHStackPeekTests.o CHStackPopTests.o CHStackPushTests.o AllTests.o CuTest.o CuTestTest.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stackTests: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ stackTests 
