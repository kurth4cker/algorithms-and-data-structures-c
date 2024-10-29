CC = cc

CFLAGS = -g -pedantic -Wall -Werror

COMMON_CFLAGS = -std=c99 -I. $(CFLAGS)

BINARIES = main
OBJECTS = \
	alist.o \
	array.o \
	astack.o \
	aqueue.o \
	lstack.o \
	lqueue.o \
	slist.o \
	qdeque.o
HEADERS = $(OBJECTS:.o=.h)

all: $(BINARIES)

alist.o: alist.h
array.o: array.h
astack.o: astack.h
aqueue.o: aqueue.h
lstack.o: lstack.h slist.h
lqueue.o: lqueue.h slist.h
main.o: $(HEADERS)
slist.o: slist.h
qdeque.o: qdeque.h

main: main.o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $< $(OBJECTS) $(LDLIBS)

clean:
	rm -f $(BINARIES) *.o

.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CC) $(COMMON_CFLAGS) -c -o $@ $<
