FLAGS = -Wall -Wextra -DDEBUG -g -std=c++14
PROJNAME = program1

all: program1.o Star.o Planet.o Vector.o List.o
	g++ $(FLAGS) program1.o Star.o Planet.o Vector.o List.o -o $(PROJNAME)

program1.o: program1.cpp
	g++ $(FLAGS) -c program1.cpp -o program1.o

Planet.o: Planet.cpp
	g++ $(FLAGS) -c Planet.cpp -o Planet.o

Star.o: Star.cpp
	g++ $(FLAGS) -c Star.cpp -o Star.o

Vector.o: Vector.cpp
	g++ $(FLAGS) -c Vector.cpp -o Vector.o

List.o: List.cpp
	g++ $(FLAGS) -c List.cpp -o List.o

run: all
	./$(PROJNAME)
memcheck: all
	valgrind ./$(PROJNAME)
clean:
	rm -rf *.o
	rm -rf $(PROJNAME)
