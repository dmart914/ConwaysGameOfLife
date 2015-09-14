#Dave Martinez
#CS162 Winter 2015
#Assignment 1 - makefile

#compiler
CXX = g++

#flags
CXXFLAGS = -std=c++0x
CSSFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#all objects
OBJS = Cell.o Board.o variables.o functions.o main.o 

#all sources
SRCS = Cell.cpp Board.cpp variables.cpp functions.cpp main.cpp

#all headers
HEADERS = Cell.h Board.h functions.h


#targets
#everything
default: $(SRCS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o gameOfLife

#everything and tidy up
allandclean: default clean	

#Cell - create the Cell object
Cell.o: Cell.cpp
	$(CXX) $(CXXFLAGS) -c Cell.cpp

#Board - create the Board object
Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

#functions - create the functions object
functions.o: functions.cpp
	$(CXX) $(CXXFLAGS) -c functions.cpp

#variables - create the variables object
variables.o: variables.cpp
	$(CXX) $(CXXFLAGS) -c variables.cpp

#main - create the main object
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

#clean
clean:
	rm -rf *.o