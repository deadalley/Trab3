CC = g++
CFLAGS = -c -g
IFLAGS = -Iinclude
SRCDIR = src
OBJDIR = obj
SRC = team.cpp inventory.cpp item.cpp armor.cpp weapon.cpp character.cpp main.cpp knight.cpp wizard.cpp thief.cpp potion.cpp manapotion.cpp healthpotion.cpp
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

all: trab3

trab2: $(OBJ) obj/main.o
	$(CC) -g $(IFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@

obj/main.o: main.cpp
	$(CC) $(CFLAGS) $(IFLAGS) main.cpp -o obj/main.o

clean:
	rm -rf obj/*.o trab1

val:
	valgrind --leak-check=full --track-origins=yes ./trab3

run: trab3
	@./trab3
