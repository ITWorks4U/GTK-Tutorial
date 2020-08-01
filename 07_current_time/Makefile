FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic
TARGET=07_time_widget.run
SOURCE=src/main.c
FULL_COMPILE=-Wall -g3

all:
		@gcc $(FULL_COMPILE) $(SOURCE) -o $(TARGET) $(FLAGS)
		$(info Building successful)

clean:
		@rm $(TARGET)
		$(info Removing successful)
