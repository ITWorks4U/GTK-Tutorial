#include "../header/radio_button_only.h"
#include <stdlib.h>

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWidget *window = NULL;
	
	/*	---	structure to use ---	*/
	struct SRadioButton *radio = g_slice_new(struct SRadioButton);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/radio_buttons.glade");	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	
	/*	---	initialize widgets	---	*/
	radio->rb_01 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, NAME_RB_01));
	radio->lbl_for_radio_buttons = GTK_LABEL(gtk_builder_get_object(builder, NAME_LABEL_RB_BUTTON));
		
	/*	connect signals to the builder	*/
	gtk_builder_connect_signals(builder, radio);
	
	g_object_unref(builder);
	gtk_widget_show(window);
	gtk_main();
	
	/*	---	release allocated memory ---		*/
	g_slice_free(struct SRadioButton, radio);
	
	return EXIT_SUCCESS;
}

/*	event handler for window	*/
void main_window_destroy_cb(void) {
	gtk_main_quit();
}

/*	event for radio button activity	*/
void rb_01_toggled_cb(GtkRadioButton *rbtn, struct SRadioButton *radio) {
	gtk_label_set_text(radio->lbl_for_radio_buttons, "option 1 selected");
}

void rb_02_toggled_cb(GtkRadioButton *rbtn, struct SRadioButton *radio) {
	gtk_label_set_text(radio->lbl_for_radio_buttons, "option 2 selected");
}

void rb_03_toggled_cb(GtkRadioButton *rbtn, struct SRadioButton *radio) {
	gtk_label_set_text(radio->lbl_for_radio_buttons, "option 3 selected");
}
