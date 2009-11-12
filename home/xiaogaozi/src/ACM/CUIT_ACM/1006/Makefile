CC = gcc
CCFLAG = -Wall -g
OBJECT = 1006.o

1006: $(OBJECT)
	$(CC) $(CCFLAG) -o 1006 $(OBJECT)

1006.o: 1006.c
	$(CC) $(CCFLAG) -c 1006.c

clean:
	rm -f $(OBJECT)
