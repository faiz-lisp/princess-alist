CC = gcc
CCFLAG = -Wall -g
OBJECT = f4.9.o ../../error/err.o

f4.9: $(OBJECT)
	$(CC) $(CCFLAG) -o f4.9 $(OBJECT)

f4.9.o: f4.9.c
	$(CC) $(CCFLAG) -c f4.9.c

err.o: ../../error/err.c
	$(CC) $(CCFLAG) -c ../../error/err.c

clean:
	rm -f $(OBJECT)
