CC = gcc
CCFLAG = -Wall -g
OBJECT = 1007.o

1007: $(OBJECT)
	$(CC) $(CCFLAG) -o 1007 $(OBJECT)

1007.o: 1007.c
	$(CC) $(CCFLAG) -c 1007.c

clean:
	rm -f $(OBJECT)
