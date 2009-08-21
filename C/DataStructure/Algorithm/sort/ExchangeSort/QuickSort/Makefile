CC = gcc
CCFLAG = -Wall -g
LOCFLAG = -I ../../../../LinearList/sqlist/
OBJECT = quicksort.o

quicksort: quicksort.o
	$(CC) $(CCFLAG) -o quicksort $(OBJECT)

quicksort.o: quicksort.c ../../../../LinearList/sqlist/sqlist.h
	$(CC) $(CCFLAG) $(LOCFLAG) -c quicksort.c

clean:
	rm -r $(OBJECT)
