FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic
TARGET=09_fileChooser.run
SOURCES=src/main.c src/logic.c
HEADER=header/fileChooser.h
FULL_COMPILE=-Wall -g3

all:
		@gcc $(FULL_COMPILE) $(SOURCES) $(HEADER) -o $(TARGET) $(FLAGS)
		$(info Building successful)

clean:
		@rm $(TARGET)
		$(info Removing successful)
