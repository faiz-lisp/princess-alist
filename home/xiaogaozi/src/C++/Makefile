CC = g++
CCFLAG = -Wall -g
OBJECT = alist.o

alist: $(OBJECT)
	$(CC) $(CCFLAG) -o alist $(OBJECT)

alist.o: alist.cpp
	$(CC) $(CCFLAG) -c alist.cpp

clean:
	rm -f $(OBJECT)