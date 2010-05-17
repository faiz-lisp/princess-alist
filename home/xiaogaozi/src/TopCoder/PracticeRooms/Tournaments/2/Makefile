CC = g++
CFLAGS = -Wall -g
# CPPFLAGS = -I
# LDFLAGS = -L
EXEC = 250 500 1000

all: $(EXEC)

250: 250.o
	$(CC) $(CFLAGS) -o $@ $^

250.o: 250.cpp
	$(CC) $(CFLAGS) -c $^

500: 500.o
	$(CC) $(CFLAGS) -o $@ $^

500.o: 500.cpp
	$(CC) $(CFLAGS) -c $^

1000: 1000.o
	$(CC) $(CFLAGS) -o $@ $^

1000.o: 1000.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o $(EXEC)
