#ifndef CHECKBOX_BUTTON_ONLY_H
#define CHECKBOX_BUTTON_ONLY_H

#include <gtk/gtk.h>

struct SCheckBoxButton {
	GtkCheckButton *check_button_01;
	GtkCheckButton *check_button_02;
	GtkCheckButton *check_button_03;
	GtkLabel *lbl_for_check_buttons;
};

#define	NAME_CHECK_01			"check_01"
#define	NAME_CHECK_02			"check_02"
#define	NAME_CHECK_03			"check_03"
#define NAME_LABEL_CHECK_BUTTON	"lbl_for_check_buttons"

#define	STATE_PRESSED			"PRESSED"
#define STATE_UNPRESSED			"UNPRESSED"

void updateTextForCheckBoxLabel(GtkCheckButton *button, const char *message, struct SCheckBoxButton *checkBox);

#endif
