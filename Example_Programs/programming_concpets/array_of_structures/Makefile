# Written considering Linux OS only
PROJ_NAME = BOX_ARRAY.out
BUILD_DIR = Build

SRC = Array_of_boxes.c

all:$(SRC)
	gcc $^ -o $(PROJ_NAME)

run: all
	./$(PROJ_NAME)

analyze: all memcheck staticcheck coverage codesize sanitize_check

staticcheck:
	cppcheck --enable=all .

memcheck:
	valgrind ./$(PROJ_NAME)

sanitize_check:
	gcc -fsanitize=address -fno-omit-frame-pointer $(SRC) -o $(PROJ_NAME)
	./$(PROJ_NAME)

coverage:$(SRC)
	gcc -fprofile-arcs -ftest-coverage $< -o $(PROJ_NAME)
	./$(PROJ_NAME)
	gcov -a $(SRC)

codesize:$(PROJ_NAME)
	size $^

clean:
	rm -rf $(PROJ_NAME) *.gcov *.gcda *.gcno
