CC = gcc
CCFLAG = -Wall -g
OBJECT = f4.3.o ../../error/err.o

f4.3: $(OBJECT)
	$(CC) $(CCFLAG) -o f4.3 $(OBJECT)

f4.3.o: f4.3.c
	$(CC) $(CCFLAG) -c f4.3.c

err.o: ../../error/err.c
	$(CC) $(CCFLAG) -c ../../error/err.c

clean:
	rm -f $(OBJECT)
