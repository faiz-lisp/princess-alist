CC = gcc
CCFLAG = -Wall -g
# LOCFLAG = -I
OBJECT = alist.o

alist: $(OBJECT)
	$(CC) $(CCFLAG) -o alist $(OBJECT)

alist.o: alist.c
	$(CC) $(CCFLAG) -c alist.c

clean:
	rm -f $(OBJECT)
