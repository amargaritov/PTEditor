all: tests

tests: tests.c utest.h ../ptedit_header.h
	gcc tests.c -std=gnu99 -o tests -fsanitize=address
	gcc print_pt.c -std=gnu99 -o print_pt -fsanitize=address

clean:
	rm -f tests
	
