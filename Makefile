CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/map.c src/game.c src/io.c src/player.c src/util.c
OUT = build/Firestorm.exe

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f build/*.exe
