all:
	g++ -O3 -Wall -Wextra -std=c++23 -o tsmat *.cpp

clean:
	rm -f main
