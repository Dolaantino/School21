
CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURCES=cipher.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/Quest_1-2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@