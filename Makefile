VPATH = SRC INCLUDE
CXXFLAGS += --std=c++11

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: main.o order.o serving.o scoop.o container.o topping.o item.o
	$(CXX) $(CXXFLAGS) -o main main.o order.o serving.o scoop.o container.o topping.o item.o
	./main
main.o: main.cpp order.h order.h serving.h scoop.h container.h topping.h
	$(CXX) $(CXXFLAGS) -c main.cpp
order.o: order.cpp order.h
	$(CXX) $(CXXFLAGS) -c order.cpp
serving.o: serving.cpp serving.h
	$(CXX) $(CXXFLAGS) -c serving.cpp
topping.o: topping.cpp topping.h
	$(CXX) $(CXXFLAGS) -c topping.cpp
scoop.o: scoop.cpp scoop.h
	$(CXX) $(CXXFLAGS) -c scoop.cpp
container.o: container.cpp container.h
	$(CXX) $(CXXFLAGS) -c container.cpp
item.o: item.cpp item.h
	$(CXX) $(CXXFLAGS) -c item.cpp
clean:
	-rm -f *.o *~ main
