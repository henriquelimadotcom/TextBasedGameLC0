CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS =

SRCS = src/main.cpp src/Game.cpp
HEADERS = include/Game.h
OBJS = $(SRCS:.cpp=.o)

EXEC = lc0_game

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iinclude -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXEC)
