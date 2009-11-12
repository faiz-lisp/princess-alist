CC = gcc
CCFLAG = -Wall -g
OBJECT = 1002.o

1002: $(OBJECT)
	$(CC) $(CCFLAG) -o 1002 $(OBJECT)

1002.o: 1002.c
	$(CC) $(CCFLAG) -c 1002.c

clean:
	rm -f $(OBJECT)
