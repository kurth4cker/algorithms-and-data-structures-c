CC = cc

CFLAGS = -g -pedantic -Wall -Werror

COMMON_CFLAGS = -std=c99 -I. $(CFLAGS)

BINARIES = main
OBJECTS = \
	array.o \
	astack.o \
	aqueue.o \
	lstack.o \
	lqueue.o \
	slist.o \
	sl_hashtable.o \
	snode.o \
	qdeque.o \
	tree.o
HEADERS = $(OBJECTS:.o=.h)

all: $(BINARIES)

array.o: array.h
astack.o: astack.h
aqueue.o: aqueue.h
lstack.o: lstack.h slist.h
lqueue.o: lqueue.h slist.h
main.o: $(HEADERS)
slist.o: slist.h snode.h
sl_hashtable.o: sl_hashtable.h snode.h
snode.o: snode.h
qdeque.o: qdeque.h
tree.o: tree.h person.h

main: main.o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $< $(OBJECTS) $(LDLIBS)

clean:
	rm -f $(BINARIES) *.o

.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CC) $(COMMON_CFLAGS) -c -o $@ $<
