CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS =

TARGET = PGO

#Defaults
all: $(TARGET)

$(TARGET): main.o importData.o assessData.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) main.o importData.o assessData.o


main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

importData.o: importData.cc
	$(CXX) $(CXXFLAGS) -c importData.cc

assessData.o: assessData.cc
	$(CXX) $(CXXFLAGS) -c assessData.cc

#The optimizations required

o3:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -O3" clean all

lto:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -O3 -flto" \
			LDFLAGS="-flto" clean all

gcov:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -fprofile-arcs -ftest-coverage" \
			LDFLAGS="--coverage" clean all

pgo-generate:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -O3 -fprofile-generate" \
			LDFLAGS="-fprofile-generate" clean all

pgo-use:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -O3 -fprofile-use -fprofile-correction" \
			LDFLAGS="-fprofile-use" clean all

#cleaning up

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *.gcda *.gcno *.gcov core*