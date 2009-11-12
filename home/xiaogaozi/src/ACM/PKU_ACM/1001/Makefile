CC = gcc
CCFLAG = -Wall -g
OBJECT = 1001.o

1001: $(OBJECT)
	$(CC) $(CCFLAG) -o 1001 $(OBJECT)

1001.o: 1001.c
	$(CC) $(CCFLAG) -c 1001.c

clean:
	rm -f $(OBJECT)
