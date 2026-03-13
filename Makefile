CXX = g++
SRC = main.cc importData.cc assessData.cc
OBJS = $(SRC:.cc=.o)
TARGET = PGO

#Default flags and build
CXXFLAGS = -std=c++17 -Wall -Wextra

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
    $(CXX) $(CXXFLAGS) -c $<

# Optimization: -O3
o3:
    $(MAKE) CXXFLAGS="$(CXXFLAGS) -O3" clean all

# Link-Time Optimization
lto:
    $(MAKE) CXXFLAGS="$(CXXFLAGS) -O3 -flto" clean all

# GCov (Code Coverage)
gcov:
    $(MAKE) CXXFLAGS="$(CXXFLAGS) -fprofile-arcs -ftest-coverage" \
        LDFLAGS="--coverage" clean all

# PGO: Generate profile data
pgo-generate:
    $(MAKE) CXXFLAGS="$(CXXFLAGS) -O3 -fprofile-generate" \
        LDFLAGS="-fprofile-generate" clean all

# PGO: Use profile data
pgo-use:
    $(MAKE) CXXFLAGS="$(CXXFLAGS) -O3 -fprofile-use -fprofile-correction" \
        LDFLAGS="-fprofile-use" clean all

# Clean
clean:
    rm -f $(OBJS) $(TARGET)
    rm -f *.gcda *.gcno *.gcov