<<<<<<< HEAD
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
=======
# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: program1

program1: planet.o list.o starlist.o starvector.o vector.o program1.o
	$(CC) $(CFLAGS) planet.o list.o starlist.o starvector.o vector.o program1.o -o program1

planet.o: Planet.cpp Planet.h
	$(CC) $(CFLAGS) -c Planet.cpp -o planet.o

list.o: List.cpp StarVector.h Planet.h
		$(CC) $(CFLAGS) -c List.cpp -o list.o

starlist.o: StarList.cpp StarList.h StarVector.h
		$(CC) $(CFLAGS) -c StarList.cpp -o starlist.o

starvector.o: StarVector.cpp StarVector.h Starlist.h
		$(CC) $(CFLAGS) -c StarVector.cpp -o starvector.o

vector.o: Vector.cpp Vector.h Planet.h
		$(CC) $(CFLAGS) -c Vector.cpp -o vector.o

program1.o: program1.cpp Planet.cpp Planet.h List.cpp List.h StarList.cpp StarList.h StarVector.cpp StarVector.h Vector.cpp Vector.h
	$(CC) $(CFLAGS) -c program1.cpp -o program1.o

clean:
	rm *.o program1

run: program1
	./program1

memcheck: program1
	valgrind ./program1
>>>>>>> 059369168a7153daf1af2b44f6f045ebab2559b8
