#	properties to set
TARGET=user_input.run
SOURCE=03_user_input.c

#	building
all:
		gcc -g3 -Wall $(SOURCE) -o $(TARGET) `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
clean:
		rm $(TARGET)
