CC = gcc
CCFLAG = -Wall -g
OBJECT = 1005.o

1005: $(OBJECT)
	$(CC) $(CCFLAG) -o 1005 $(OBJECT)

1005.o: 1005.c
	$(CC) $(CCFLAG) -c 1005.c

clean:
	rm -f $(OBJECT)
