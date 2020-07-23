FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic
TARGET=06_randomGenerator.run
SOURCES=src/main.c src/callbacks.c src/logic.c
HEADER=header/random_generator.h
FULL_COMPILE=-Wall -g3

all:
		@gcc $(FULL_COMPILE) $(SOURCES) $(HEADER) -o $(TARGET) $(FLAGS)
		$(info Building successful)

clean:
		@rm $(TARGET)
		$(info Removing successful)
