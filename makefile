CXX = clang++
CXXFLAGS = -std=c++17
CC = clang
CCFLAGS = -std=c17

all: stone_weight

longpal: stone_weight.cpp
	$(CXX) $(CXXFLAGS) -o stone_weight stone_weight.cpp

clean:
	rm -rf stone_weight stone_weight_debug
