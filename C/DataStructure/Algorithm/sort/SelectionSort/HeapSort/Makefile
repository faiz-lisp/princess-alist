CC = gcc
CCFLAG = -Wall -g
LOCFLAG = -I ../../../../LinearList/sqlist/
OBJECT = heapsort.o

heapsort: heapsort.o
	$(CC) $(CCFLAG) -o heapsort $(OBJECT)

heapsort.o: heapsort.c ../../../../LinearList/sqlist/sqlist.h
	$(CC) $(CCFLAG) $(LOCFLAG) -c heapsort.c

clean:
	rm -r $(OBJECT)
