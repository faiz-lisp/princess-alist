CC = gcc
CCFLAG = -Wall -g
OBJECT = f3.10.o ../error/err.o

f3.10: $(OBJECT)
	$(CC) $(CCFLAG) -o f3.10 $(OBJECT)

f3.10.o: f3.10.c
	$(CC) $(CCFLAG) -c f3.10.c

err.o: ../error/err.c
	$(CC) $(CCFLAG) -c ../error/err.c

clean:
	rm -f $(OBJECT)
