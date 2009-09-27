CC = gcc
CCFLAG = -Wall -g
OBJECT = alist.o

alist: alist.o
	$(CC) $(CCFLAG) -o alist $(OBJECT)

alist.o: alist.c sqqueue.h
	$(CC) $(CCFLAG) -c alist.c

clean:
	rm -r $(OBJECT)
