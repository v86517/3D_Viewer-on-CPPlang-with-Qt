CC = gcc
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV = --coverage
UNIT = model_tests.out
STLIB = s21_viewer.a
OS = $(shell uname -s)
GT_FLAGS = -lgtest_main -lgtest -lm -lstdc++ -pthread -lm -g
BUILD_DIR = 3dviewer
FOLDERS = controller/*.h model/*.h model/*.cc tests/*.cc view/*.h view/*.cc

ifeq ($(OS), Darwin)
    LIBS := -lcheck 
	APPLICATION = 3dviewer.app 
	OPEN = open $(APPLICATION)
else
    LIBS := -lgtest -lstdc++ -lcheck_pic -lrt -lpthread -lsubunit -lm -g
	APPLICATION = 3dviewer
	OPEN = ./$(APPLICATION)
endif

all: clean install

install: clean
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && qmake CONFIG+=qtquickcompiler ../view/3dviewer.pro && make
	make open

uninstall:
	rm -rf 3dviewer

clean:
	rm -rf *.o *.a *.gc* *.info build report *dSYM $(UNIT) Archive_3dviewer2.0 *tgz gcov_test 3dviewer

dvi:
	open dvi.html

dist: clean
	mkdir -p Archive_3dviewer2.0/src
	cp -r view/* Archive_3dviewer2.0/src/ 
	cp -r model/* Archive_3dviewer2.0/src/
	cp -r controller/* Archive_3dviewer2.0/src/ 
	cp -r tests/* Archive_3dviewer2.0/src/
	tar cvzf Archive_3dviewer2.0.tgz -C Archive_3dviewer2.0 .
	rm -rf Archive_3dviewer2.0/

tests:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CXXFLAGS) $(GT_FLAGS) model/*.cc tests/*.cc -o $(BUILD_DIR)/model_tests.out
	./$(BUILD_DIR)/model_tests.out

clang:
	clang-format -style=file:../materials/linters/.clang-format -n ./*.cc $(FOLDERS)
	clang-format -style=file:../materials/linters/.clang-format -i ./*.cc $(FOLDERS)

open:
	cd $(BUILD_DIR) && $(OPEN)

coverage:
	open report/index.html

gcov_report:
	$(CC) $(CXXFLAGS) $(GCOV) -lgtest_main model/*.cc tests/*.cc -o $(UNIT) $(LIBS)
	./$(UNIT)
	gcov model/*.cc tests/*.cc
	lcov -t "tests" -o tests.info -c -d .
	lcov --remove tests.info '/usr/*' --output-file tests_filtered.info
	lcov --remove tests_filtered.info 'tests/*' --output-file tests_final.info 
	genhtml -o report tests_final.info
	open report/index.html
