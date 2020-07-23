#!/bin/bash
#	shell script to remove executables, if these exists
#	all these programs are located at the . directory

full_program=05_toggled_buttons_full.run
toggle_program=05_toggle_button.run
check_program=05_check_boxes.run
radio_program=05_radio_button.run

if [ -f $full_program ]; then
	rm $full_program
	echo "program $full_program has been successfully removed"
fi

if [ -f $toggle_program ]; then
	rm $toggle_program
	echo "program $toggle_program has been successfully removed"
fi

if [ -f $check_program ]; then
	rm $check_program
	echo "program $check_program has been successfully removed"
fi

if [ -f $radio_program ]; then
	rm $radio_program
	echo "program $radio_program has been successfully removed"
fi
