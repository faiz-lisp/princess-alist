CC = gcc
CCFLAG = -Wall -g
LOCFLAG = -I ../../../../LinearList/sqlist/
OBJECT = bubblesort.o

bubblesort: bubblesort.o
	$(CC) $(CCFLAG) -o bubblesort $(OBJECT)

bubblesort.o: bubblesort.c ../../../../LinearList/sqlist/sqlist.h
	$(CC) $(CCFLAG) $(LOCFLAG) -c bubblesort.c

clean:
	rm -r $(OBJECT)
