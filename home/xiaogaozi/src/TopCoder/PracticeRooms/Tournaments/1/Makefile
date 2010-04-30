CC = g++
CFLAGS = -Wall -g
# CPPFLAGS = -I
# LDFLAGS = -L
EXEC = 250 500

all: $(EXEC)

250: 250.o
	$(CC) $(CFLAGS) -o $@ $^

250.o: 250.cpp
	$(CC) $(CFLAGS) -c $^

500: 500.o
	$(CC) $(CFLAGS) -o $@ $^

500.o: 500.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o $(EXEC)
