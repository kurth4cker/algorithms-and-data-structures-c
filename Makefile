CC = cc

CFLAGS = -g -pedantic -Wall -Werror

COMMON_CFLAGS = -std=c99 -I. $(CFLAGS)

BINARIES = main
OBJECTS = alist.o slist.o aqueue.o lqueue.o
HEADERS = $(OBJECTS:.o=.h)

all: $(BINARIES)

alist.o: alist.h
slist.o: slist.h
aqueue.o: aqueue.h
lqueue.o: lqueue.h slist.h

main: main.o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $< $(OBJECTS) $(LDLIBS)

clean:
	rm -f $(BINARIES) *.o

.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CC) $(COMMON_CFLAGS) -c -o $@ $<
