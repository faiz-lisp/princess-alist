CC = gcc
CCFLAG = -Wall -g
OBJECT = 1003.o

1003: $(OBJECT)
	$(CC) $(CCFLAG) -o 1003 $(OBJECT)

1003.o: 1003.c
	$(CC) $(CCFLAG) -c 1003.c

clean:
	rm -f $(OBJECT)
