/**	Contains the signal handler for the radio buttons.	*/
#include "../header/widgets.h"

void rb_01_toggled_cb(GtkRadioButton *rbtn, WidgetsToggle *toggle) {
	gtk_label_set_text(toggle->lbl_radio_button_output, "option 1 selected");
}

void rb_02_toggled_cb(GtkRadioButton *rbtn, WidgetsToggle *toggle) {
	gtk_label_set_text(toggle->lbl_radio_button_output, "option 2 selected");
}

void rb_03_toggled_cb(GtkRadioButton *rbtn, WidgetsToggle *toggle) {
	gtk_label_set_text(toggle->lbl_radio_button_output, "option 3 selected");
}
