CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++17
GTEST_LIBS = -lgtest -lgtest_main -pthread

SRC_MAIN = main.cpp game.cpp 
SRC_TESTS = tests.cpp game.cpp
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_TESTS = $(SRC_TESTS:.cpp=.o)

all: game tests

game: $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) -o game $(OBJ_MAIN)

tests: $(OBJ_TESTS)
	$(CXX) $(CXXFLAGS) -o tests $(OBJ_TESTS) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o game tests
