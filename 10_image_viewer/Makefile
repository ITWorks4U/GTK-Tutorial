FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic
TARGET=10_image_viewer.run
SOURCES=src/main.c src/image_viewer.c
HEADER=header/image_viewer.h
FULL_COMPILE=-Wall -g3

all:
		@gcc $(FULL_COMPILE) $(SOURCES) $(HEADER) -o $(TARGET) $(FLAGS)
		$(info Building successful)

clean:
		@rm $(TARGET)
		$(info Removing successful)
