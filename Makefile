VPATH = SRC INCLUDE
CXXFLAGS += --std=c++11

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: main.o main_window.o emporium.o dialogs.o order.o serving.o scoop.o container.o topping.o item.o login.o user.o customer.o server.o manager.o
	$(CXX) $(CXXFLAGS) -o main main.o main_window.o emporium.o dialogs.o order.o serving.o scoop.o container.o topping.o item.o user.o customer.o server.o manager.o login.o `pkg-config gtkmm-3.0 --cflags --libs`
	./main
main.o: main.cpp order.h order.h serving.h scoop.h container.h topping.h login.h main_window.h
	$(CXX) $(CXXFLAGS) -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs`
main_window.o: main_window.cpp main_window.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp `pkg-config gtkmm-3.0 --cflags --libs`
dialogs.o: dialogs.cpp dialogs.h
	$(CXX) $(CXXFLAGS) -c dialogs.cpp `pkg-config gtkmm-3.0 --cflags --libs`
order.o: order.cpp order.h
	$(CXX) $(CXXFLAGS) -c order.cpp
serving.o: serving.cpp serving.h
	$(CXX) $(CXXFLAGS) -c serving.cpp

#item objects
topping.o: topping.cpp topping.h
	$(CXX) $(CXXFLAGS) -c topping.cpp
scoop.o: scoop.cpp scoop.h
	$(CXX) $(CXXFLAGS) -c scoop.cpp
container.o: container.cpp container.h
	$(CXX) $(CXXFLAGS) -c container.cpp
item.o: item.cpp item.h
	$(CXX) $(CXXFLAGS) -c item.cpp

#user objects
user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c user.cpp
customer.o: customer.cpp customer.h
	$(CXX) $(CXXFLAGS) -c customer.cpp
server.o: server.cpp server.h
	$(CXX) $(CXXFLAGS) -c server.cpp
manager.o: manager.cpp manager.h
	$(CXX) $(CXXFLAGS) -c manager.cpp
	
emporium.o: emporium.cpp emporium.h
	$(CXX) $(CXXFLAGS) -c emporium.cpp
login.o: login.cpp login.h
	$(CXX) $(CXXFLAGS) -c login.cpp
clean:
	-rm -f *.o *~ main
