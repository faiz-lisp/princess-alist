CC = gcc
CCFLAG = -Wall -g
OBJECT = 1004.o

1004: $(OBJECT)
	$(CC) $(CCFLAG) -lm -o 1004 $(OBJECT)

1004.o: 1004.c
	$(CC) $(CCFLAG) -c 1004.c

clean:
	rm -f $(OBJECT)
