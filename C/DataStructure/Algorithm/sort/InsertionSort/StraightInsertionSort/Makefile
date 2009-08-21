CC = gcc
CCFLAG = -Wall -g
LOCFLAG = -I ../../../../LinearList/sqlist/
OBJECT = sis.o

sis: sis.o
	$(CC) $(CCFLAG) -o sis $(OBJECT)

sis.o: sis.c ../../../../LinearList/sqlist/sqlist.h
	$(CC) $(CCFLAG) $(LOCFLAG) -c sis.c

clean:
	rm -r $(OBJECT)
