CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -Ithird_party/googletest/googletest/include -Ithird_party/googletest/googletest -pthread

# Source files
MATRIX_SRC = matrix.cpp
HEADER = matrix.hpp

# Targets
all: matrix_test matrix_cli

matrix_test: $(MATRIX_SRC) tests/tests.cpp test_main.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -o matrix_test $(MATRIX_SRC) tests/tests.cpp test_main.cpp third_party/googletest/googletest/src/gtest-all.cc

matrix_cli: $(MATRIX_SRC) main.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -o matrix_cli $(MATRIX_SRC) main.cpp

clean:
	rm -f matrix_test matrix_cli
