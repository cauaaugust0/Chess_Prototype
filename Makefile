CC = gcc

TARGET = main.exe

CFLAGS = -Wall -Wextra \
          -Iraylib/include \
          -Iinclude

LDFLAGS = -Lraylib/lib

LIBS = -lraylib -lgdi32 -lwinmm -lopengl32

SRC = main.c \
	  $(wildcard src/*.c) \
      $(wildcard src_game/*.c) \
	  $(wildcard src_pieces/*.c) \
	  $(wildcard util/*.c) \

all:
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)