CC = gcc
CCFLAG = -Wall -g
OBJECT = 3.2.o ../../error/err.o

3.2: $(OBJECT)
	$(CC) $(CCFLAG) -o 3.2 $(OBJECT)

3.2.o: 3.2.c
	$(CC) $(CCFLAG) -c 3.2.c

err.o: ../../error/err.c
	$(CC) $(CCFLAG) -c ../../error/err.c

clean:
	rm -f $(OBJECT)
