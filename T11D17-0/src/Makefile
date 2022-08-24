CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURCES=dmanager_module.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/Quest_1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o
	rm -rf ../build/*
rebuild: clean all