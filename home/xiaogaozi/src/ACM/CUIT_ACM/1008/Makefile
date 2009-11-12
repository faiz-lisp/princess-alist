CC = gcc
CCFLAG = -Wall -g
OBJECT = 1008.o

1008: $(OBJECT)
	$(CC) $(CCFLAG) -o 1008 $(OBJECT)

1008.o: 1008.c
	$(CC) $(CCFLAG) -c 1008.c

clean:
	rm -f $(OBJECT)
