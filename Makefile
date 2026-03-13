CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

OBJS = main.o importData.o assessData.o

TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cc importData.h assessData.h
	$(CXX) $(CXXFLAGS) -c main.cc

importData.o: importData.cc importData.h sleepData.h
	$(CXX) $(CXXFLAGS) -c importData.cc

assessData.o: assessData.cc assessData.h sleepData.h
	$(CXX) $(CXXFLAGS) -c assessData.cc

clean:
	rm -f *.o $(TARGET)