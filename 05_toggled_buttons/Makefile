#	macro to use everywhere
FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic

#	full program build
SOURCES=src/main.c src/signal_toggled_button.c src/signal_check_box.c src/signal_radio_buttons.c
HEADERS=header/widgets.h header/names.h
TARGET_FULL=05_toggled_buttons_full.run

#	toggle button only
SRC_TOGGLE=src/toggle_button_only.c
HEADER_TOGGLE=header/toggle_button_only.h
TARGET_TOGGLE=05_toggle_button.run

#	check_box_buttons onlny
SRC_CHECK_BOX=src/checkbox_button_only.c
HEADER_CHECK_BOX=header/checkbox_button_only.h
TARGET_CHECK_BOX=05_check_boxes.run

#	radio_buttons only
SRC_RADIO_BUTTON=src/radio_button_only.c
HEADER_RADIO_BUTTON=header/radio_button_only.h
TARGET_RADIO_BUTTON=05_radio_button.run

#	building sequences
all:
			@gcc -g3 -Wall $(SOURCES) $(HEADERS) -o $(TARGET_FULL) $(FLAGS)
			$(info Building of "$(TARGET_FULL)" was successful.)
			
toggle:
			@gcc -g3 -Wall $(SRC_TOGGLE) $(HEADER_TOGGLE) -o $(TARGET_TOGGLE) $(FLAGS)
			$(info $(TARGET_TOGGLE) successfully build)

radio:
			@gcc -g3 -Wall $(SRC_RADIO_BUTTON) $(HEADER_RADIO_BUTTON) -o $(TARGET_RADIO_BUTTON) $(FLAGS)
			$(info $(TARGET_RADIO_BUTTON) successfully build)
			
check:
			@gcc -g3 -Wall $(SRC_CHECK_BOX) $(HEADER_CHECK_BOX) -o $(TARGET_CHECK_BOX) $(FLAGS)
			$(info $(TARGET_CHECK_BOX) successfully build)
			
clean:
			@bash remove_executable.sh
