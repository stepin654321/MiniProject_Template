PROJECT=COMPLEX_CAL

SRC=src/complex_cal.c

TEST= test/test_complex_cal.c\
unity/unity.c

INC=-I inc\
-I unity

.PHONY: run clean test doc all

$(PROJECT):all

all: $(SRC) $(TEST)
	gcc $(INC) $(TEST) $(SRC) -o $(PROJECT).out

test: $(SRC) $(TEST)
	gcc $(INC) $(TEST) $(SRC) -o $(PROJECT).out
	./$(PROJECT).out

run: $(PROJECT)
	./$(PROJECT).out

clean: 
	rm $(PROJECT).out	



