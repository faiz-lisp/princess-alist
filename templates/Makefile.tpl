CC = gcc
CFLAGS = -Wall -g
# CPPFLAGS = -I
# LDFLAGS = -L
OBJECT = alist.o

alist: $(OBJECT)
	$(CC) $(CFLAGS) -o alist $(OBJECT)

alist.o: alist.c
	$(CC) $(CFLAGS) -c alist.c

clean:
	rm -f alist $(OBJECT)
