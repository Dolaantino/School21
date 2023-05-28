CFLAGS = -Wall -Werror -Wextra -std=c11
ARCH = $(shell arch)
ifeq "$(ARCH)" "i386"
MYFLAGS = -lcheck -lpthread -lm  -I /usr/local/include -L/usr/local/lib
endif
ifeq "$(ARCH)" "x86_64"
MYFLAGS = -lcheck -lm -lpthread -lsubunit -g
endif

all: clean test gcov_report

dvi:
	open README.md

install:
	
	cd Calculator && qmake && make
	rm -rf build

dist:
	tar -cf SmartCalc_v1.0.tar Calculator

uninstall:
	cd Calculator && rm -rf *.user Calculator.app a.out.dSYM .qmake.stash

vpath %.c model:model/tests/ test

test: 
	cd Calculator && gcc *.c $^ -o $@ $(CFLAGS) $(MYFLAGS) --coverage

gcov_report: test
	cd Calculator && ./test
	cd Calculator && gcovr --html-details rep.html
	cd Calculator && open rep.html

check:
	cp ../materials/linters/.clang-format .
	clang-format -n Calculator/*.c
	clang-format -n Calculator/*.h
	clang-format -n Calculator/*.cpp

clean:
	rm -rf *.o *.gcda *.a *.html *.gcno *.css .clang-format build 
	rm -f test
	rm -rf *.tar.gz
	rm -rf Calculator/*.o Calculator/*.gcno Calculator/*.gcda Calculator/*.html Calculator/*.css Calculator/test Calculator/*.user

rebuild: clean all