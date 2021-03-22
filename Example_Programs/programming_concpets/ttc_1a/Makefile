PROJECT_NAME = ComplexNum_calculator
SRC =  src/c_div.c \
src/c_mul.c \
src/c_sub.c \
src/c_sum.c \
test_v1.c

INC_T = unity
INC_H = inc

TEST = unity/unity.c
$(PROJECT_NAME).exe : $(SRC) $(TEST)
	gcc -I $(INC_H) -I $(INC_T) $(SRC) $(TEST) -o $(PROJECT_NAME).exe

run :
	$(PROJECT_NAME).exe