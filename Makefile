
%: %.bf main
	./main < $< > $@.s
	as $@.s -o $@.o
	ld $@.o -o $@
	# rm $@.s $@.o

main: main.cpp assembler.h instructions.h
	g++ -g3 -pedantic -Wall -Werror $^ -o main