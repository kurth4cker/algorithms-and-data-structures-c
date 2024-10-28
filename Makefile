CC = cc

CFLAGS = -g -pedantic -Wall -Werror

COMMON_CFLAGS = -std=c99 -I. $(CFLAGS)

BINARIES = main
OBJECTS = alist.o aqueue.o lqueue.o slist.o astack.o
HEADERS = $(OBJECTS:.o=.h)

all: $(BINARIES)

alist.o: alist.h
astack.o: astack.h
aqueue.o: aqueue.h
lqueue.o: lqueue.h slist.h
main.o: $(HEADERS)
slist.o: slist.h

main: main.o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $< $(OBJECTS) $(LDLIBS)

clean:
	rm -f $(BINARIES) *.o

.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CC) $(COMMON_CFLAGS) -c -o $@ $<
