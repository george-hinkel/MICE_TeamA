VPATH = SRC INCLUDE
CXXFLAGS += --std=c++11

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: main.o order.o serving.o scoop.o container.o login.o
	$(CXX) $(CXXFLAGS) -o main main.o order.o serving.o scoop.o container.o login.o
main.o: main.cpp order.h order.h serving.h scoop.h container.h login.h
	$(CXX) $(CXXFLAGS) -c main.cpp
order.o: order.cpp order.h
	$(CXX) $(CXXFLAGS) -c order.cpp
serving.o: serving.cpp serving.h
	$(CXX) $(CXXFLAGS) -c serving.cpp
scoop.o: scoop.cpp scoop.h
	$(CXX) $(CXXFLAGS) -c scoop.cpp
container.o: container.cpp container.h
	$(CXX) $(CXXFLAGS) -c container.cpp
login.o: login.cpp login.h
	$(CXX) $(CXXFLAGS) -c login.cpp
clean:
	-rm -f *.o *~ main
