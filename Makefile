CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lSDL2 -lSDL2_ttf
SOURCES=main.cpp Character/Character.cpp GameManager/GameManager.cpp Map/Mapp.cpp Room/Room.cpp Room/Traproom/Traproom.cpp Room/Winroom/Winroom.cpp Character/Monster/Monster.cpp Character/Player/Player.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=start_game

.PHONY: all clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)