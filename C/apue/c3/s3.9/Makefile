CC = gcc
CCFLAG = -Wall -g
OBJECT = f3.4.o ../error/err.o

f3.4: $(OBJECT)
	$(CC) $(CCFLAG) -o f3.4 $(OBJECT)

f3.4.o: f3.4.c
	$(CC) $(CCFLAG) -c f3.4.c

err.o: ../error/err.c
	$(CC) $(CCFLAG) -c ../error/err.c

clean:
	rm -f $(OBJECT)
