CC = gcc
CCFLAG = -Wall -g
LOCFLAG = -I ../../../LinearList/sqlist/
OBJECT = bisearch.o

bisearch: bisearch.o
	$(CC) $(CCFLAG) -o bisearch $(OBJECT)

bisearch.o: bisearch.c ../../../LinearList/sqlist/sqlist.h
	$(CC) $(CCFLAG) $(LOCFLAG) -c bisearch.c

clean:
	rm -r $(OBJECT)
