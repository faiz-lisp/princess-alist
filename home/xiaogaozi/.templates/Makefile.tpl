CC = gcc
CFLAGS = -Wall -g
# CPPFLAGS = -I
# LDFLAGS = -L
OBJECT = alist.o

alist: $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

alist.o: alist.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJECT) alist
