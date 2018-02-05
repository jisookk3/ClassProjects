# Makefile for Assignment 3
CXX = /usr/bin/g++
ASSIGNMENT = 3
ASSIGNMENT_NAME = assignment_${ASSIGNMENT}
MAIN = ${ASSIGNMENT_NAME}_unit_test
CPP_FILES = string_list.cpp string_ui.cpp CinReader.cpp
H_FILES = string_list.h string_ui.cpp
CXXFLAGS = -Wall -Wextra -pedantic -g

options: 
	@echo
	@echo Options
	@echo ----------------------------------------
	@echo 'make              - View these options'
	@echo 'make string_list  - Compiles the unit test for StringList'
	@echo 'make string_ui    - Compiles the UI Application'
	@echo 'make style        - Runs the class style check'
	@echo 'make clean        - Deletes your executable'
	@echo 
	@echo 
	@echo "Once you've created your executable use the following to test"
	@echo './${ASSIGNMENT_NAME}     - Run the Interactive Unit Test'

# Type 'make string_ui' to create the executable
string_ui: main.cpp ${H_FILES} ${CPP_FILES}
	${CXX} ${CXXFLAGS} main.cpp ${CPP_FILES} -o ${ASSIGNMENT_NAME}
	@echo
	@echo 'Compiled! (Fix any warnings above)'

string_list: ${MAIN}.cpp string_list.h string_list.cpp
	${CXX} ${CXXFLAGS} ${MAIN}.cpp string_list.cpp -o ${ASSIGNMENT_NAME}
	@echo
	@echo 'Compiled! (Fix any warnings above)'

# Type 'make style' to check your code style
s style: ../../helpful_files/cpplint.py
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${H_FILES} ${CPP_FILES}

# Type 'make clean' to remove the executable
c clean:
	rm -rf ${ASSIGNMENT_NAME}
