TARGET = main
CC = gcc
CFLAGS = -g -Wall
OBJECTS = cards.o util.o main.o blackjack.o

default: $(TARGET)
all: default

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
