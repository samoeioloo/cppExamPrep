# This is a Makefile comment

# Declare some variables to help construct our compile command
CC=g++         # the compiler
LIBS=-std=c++2a   # the libraries we will ref

# Need object files Fib.o and FibDriver.o to create exe fibonacci
ExamPractice: ExamPractice.cpp
	$(CC) -c ExamPractice.cpp $(LIBS) && $(CC) ExamPractice.o -o ExamPractice.exe $(LIBS)

inheritance: Inheritance.cpp
	$(CC) -c Inheritance.cpp $(LIBS) && $(CC) Inheritance.o -o Inheritance.exe && ./Inheritance.exe

pointers: pointers.cpp
	$(CC) -c pointers.cpp $(LIBS) && $(CC) pointers.o -o pointers.exe && ./pointers.exe

playground: playground.cpp
	$(CC) -c playground.cpp $(LIBS) && $(CC) playground.o -o playground.exe && ./playground.exe

all: pointers inheritance
	@echo "Targets ran:" $^;

# deletes all the object code files
clean:
	@rm -f *.o
	@rm *.exe

# copies/moves the relevant binaries and/or libraries to the correct folders
run: default
	./ExamPractice.exe $ARGS
