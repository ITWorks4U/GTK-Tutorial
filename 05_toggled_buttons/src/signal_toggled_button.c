/**	Contains the signal handler for the toggled button.	*/
#include "../header/widgets.h"

void toggled_button_toggled_cb(GtkToggleButton *toggleButton, WidgetsToggle *toggle) {
	gboolean buttonState = gtk_toggle_button_get_active(toggleButton);
	
	if (buttonState) {
		gtk_label_set_text(toggle->lbl_tgl_output, "result: toggled");
	} else {
		gtk_label_set_text(toggle->lbl_tgl_output, "result: not toggled");
	}
}
