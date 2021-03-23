TARGET=hall.out
OBJS=test.o sum.o sqr.o

all:${TARGET}

$(TARGET):${OBJS}
	gcc $^ -o $@
%.o:%.c fun.h               # pattern based rule
	gcc $< -c -g
clean:
	rm -rf *.o ${TARGET}
