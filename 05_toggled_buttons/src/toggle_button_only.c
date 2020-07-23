#include "../header/toggle_button_only.h"
#include <stdlib.h>

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWidget *window = NULL;
	
	/*	---	structure to use ---	*/
	struct SToggleButton *toggle = g_slice_new(struct SToggleButton);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/toggle_button.glade");	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	
	/*	---	initialize widgets	---	*/
	toggle->tgl_button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, NAME_TOGGLE_BUTTON));
	toggle->lbl_for_toggle_button = GTK_LABEL(gtk_builder_get_object(builder, NAME_LABEL_TOGGLE_BUTTON));
		
	/*	connect signals to the builder	*/
	gtk_builder_connect_signals(builder, toggle);
	
	g_object_unref(builder);
	gtk_widget_show(window);
	gtk_main();
	
	/*	---	release allocated memory ---		*/
	g_slice_free(struct SToggleButton, toggle);
	
	return EXIT_SUCCESS;
}

/*	event handler for window	*/
void main_window_destroy_cb(void) {
	gtk_main_quit();
}

/*	event for toggle button activity	*/
void toggle_button_toggled_cb(GtkToggleButton *tglButton, struct SToggleButton *tgl_button_struct) {
	gboolean buttonState = gtk_toggle_button_get_active(tglButton);
	
	if (buttonState) {
		gtk_label_set_text(tgl_button_struct->lbl_for_toggle_button, "result: toggled");
	} else {
		gtk_label_set_text(tgl_button_struct->lbl_for_toggle_button, "result: not toggled");
	}
}
