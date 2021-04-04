# comments

#Target : dependancy
#<TAB>Command

var=result
src =src\open_file.c src\read_file.c src\free_file.c src\sort_file.c main.c inc\header.h
src_test=test_unity\test.c test_unity\unity.c test_unity\unity.h test_unity\unity_internals.h
INC_var=inc
$(var):$(src)
	gcc $(src) -I$(INC_var) -o $(var)

run:$(var)
	$(var)

static_check:
	cppcheck --enable=all src/ .c inc/ .c

rungo:
	gcc -I$(INC_var) -I test_unity $(src_test) $(src) -o test_result
	


clean:
	del /q *.exe
