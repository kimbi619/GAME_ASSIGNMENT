CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lSDL2 -lSDL2_ttf
SOURCES=main.cpp Character/Character.cpp Room/Room.cpp Character/Monster/Monster.cpp Character/Player/Player.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=alpha

.PHONY: all clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)