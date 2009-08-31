CC = gcc
CCFLAG = -Wall -g
OBJECT = f4.8.o ../../error/err.o

f4.8: $(OBJECT)
	$(CC) $(CCFLAG) -o f4.8 $(OBJECT)

f4.8.o: f4.8.c
	$(CC) $(CCFLAG) -c f4.8.c

err.o: ../../error/err.c
	$(CC) $(CCFLAG) -c ../../error/err.c

clean:
	rm -f $(OBJECT)
