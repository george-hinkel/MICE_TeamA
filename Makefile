main: main.cpp
	g++ --std=c++11 -o main main.cpp
	./main
clean:
	-rm -f *.o main
