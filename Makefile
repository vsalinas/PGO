all: PGO

PGO: main.o importData.o assessData.o
	g++ -std=c++17 -Wall -Wextra -o PGO main.o importData.o assessData.o

main.o: main.cc
	g++ -std=c++17 -Wall -Wextra -c main.cc

importData.o: importData.cc
	g++ -std=c++17 -Wall -Wextra -c importData.cc

assessData.o: assessData.cc
	g++ -std=c++17 -Wall -Wextra -c assessData.cc

clean:
	rm -f PGO *.o core* *.gcda *.gcno *.gcov
