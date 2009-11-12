CC = g++
CCFLAG = -Wall -g
OBJECT = 1002.o

1002: $(OBJECT)
	$(CC) $(CCFLAG) -o 1002 $(OBJECT)

1002.o: 1002.cpp
	$(CC) $(CCFLAG) -c 1002.cpp

clean:
	rm -f $(OBJECT)
