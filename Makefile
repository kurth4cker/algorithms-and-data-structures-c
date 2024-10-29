CC = cc

CFLAGS = -g -pedantic -Wall -Werror

COMMON_CFLAGS = -std=c99 -I. $(CFLAGS)

BINARIES = main
OBJECTS = \
	astack.o \
	aqueue.o \
	darray.o \
	farray.o \
	lstack.o \
	lqueue.o \
	slist.o \
	qdeque.o
HEADERS = $(OBJECTS:.o=.h)

all: $(BINARIES)

astack.o: astack.h
aqueue.o: aqueue.h
darray.o: darray.h
farray.o: farray.h
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
