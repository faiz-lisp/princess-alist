CC = gcc
CFLAGS = -Wall -g
OBJECT = ../../error/err.o

all: alist alistturingmachine ruptimed2

alist: $(OBJECT) f16.14.o ../s16.4/f16.9.o
	$(CC) $(CFLAGS) -o alist $(OBJECT) f16.14.o ../s16.4/f16.9.o

f16.14.o: f16.14.c
	$(CC) $(CFLAGS) -c f16.14.c

f16.9.o: ../s16.4/f16.9.c
	$(CC) $(CFLAGS) -c ../s16.4/f16.9.c

alistturingmachine: $(OBJECT) f16.15.o ../s16.4/f16.10.o ../../c13/s13.3/f13.1.o
	$(CC) $(CFLAGS) -o alistturingmachine $(OBJECT) f16.15.o ../s16.4/f16.10.o ../../c13/s13.3/f13.1.o

ruptimed2: $(OBJECT) f16.15.o ../s16.4/f16.10.o ../../c13/s13.3/f13.1.o
	$(CC) $(CFLAGS) -o ruptimed2 $(OBJECT) f16.15.o ../s16.4/f16.10.o ../../c13/s13.3/f13.1.o

f16.15.o: f16.15.c
	$(CC) $(CFLAGS) -c f16.15.c

f16.10.o: ../s16.4/f16.10.c
	$(CC) $(CFLAGS) -c ../s16.4/f16.10.c

f13.1.o: ../../c13/s13.3/f13.1.c
	$(CC) $(CFLAGS) -c ../../c13/s13.3/f13.1.c

err.o: ../../error/err.c
	$(CC) $(CFLAGS) -c ../../error/err.c

clean:
	rm -f $(OBJECT) *.o ../s16.4/f16.9.o ../s16.4/f16.10.o ../../c13/s13.3/f13.1.o alist alistturingmachine ruptimed2
