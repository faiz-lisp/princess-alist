CC = gcc
CCFLAG = -Wall -g
OBJECT = f3.2.o ../error/err.o

f3.2: $(OBJECT)
	$(CC) $(CCFLAG) -o f3.2 $(OBJECT)

f3.2.o: f3.2.c
	$(CC) $(CCFLAG) -c f3.2.c

err.o: ../error/err.c
	$(CC) $(CCFLAG) -c ../error/err.c

clean:
	rm -f $(OBJECT)
