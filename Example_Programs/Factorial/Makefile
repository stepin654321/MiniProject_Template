SRC = unity/unity.c\
src/factorial.c\
test/test_factorial.c\
main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = FACTORIAL.out

BUILD = build

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}

clean:
	rm -rf $(PROJECT_NAME)
