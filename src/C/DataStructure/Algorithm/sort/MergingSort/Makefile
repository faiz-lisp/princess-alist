CC = gcc
CCFLAG = -Wall -g
LOCFLAG = -I ../../../LinearList/sqlist/
OBJECT = msort.o

msort: msort.o
	$(CC) $(CCFLAG) -o msort $(OBJECT)

msort.o: msort.c ../../../LinearList/sqlist/sqlist.h
	$(CC) $(CCFLAG) $(LOCFLAG) -c msort.c

clean:
	rm -r $(OBJECT)
