TARGET=sall.out
OBJS=test.o src/sum.o src/sqr.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lsimple

#User created variable
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libsimple.a
	gcc -L${LIBPATH} $< -o $@
libsimple.a:src/sum.o src/sqr.o
	ar rc $@ $^
%.o:src/%.c include/fun.h

test.o: test.c include/fun.h

clean:
	rm -rf *.a *.o src/*.o ${TARGET}
