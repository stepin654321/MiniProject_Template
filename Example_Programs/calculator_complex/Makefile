PROD_NAME = prod_run
TEST_NAME = test_run
SRC = src/complex_div.c \
src/complex_mul.c \
src/complex_sub.c \
src/complex_sum.c \
main.c

SRC_TEST = src/complex_div.c \
src/complex_mul.c \
src/complex_sub.c \
src/complex_sum.c \

INC_T = unity
INC_H = inc

TEST = unity/unity.c \
test/test_complex_calculator.c

$(PROD_NAME).exe : $(SRC)
	gcc -I $(INC_H) $(SRC) -o $(PROD_NAME).exe

$(TEST_NAME).exe : $(SRC_TEST) $(TEST)
	gcc -I $(INC_H) -I $(INC_T) $(TEST) $(SRC_TEST) -o $(TEST_NAME).exe
run_prod :
	$(PROD_NAME).exe
run_test :
	$(TEST_NAME).exe