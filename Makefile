CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = matrix_test
SRC = matrix.cpp test.cpp
INC = matrix.hpp

all: $(TARGET)

$(TARGET): $(SRC) $(INC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) -lgtest -lgtest_main -pthread

clean:
	rm -f $(TARGET)
