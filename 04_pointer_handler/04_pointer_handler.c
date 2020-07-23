#include <gtk/gtk.h>
#include <stdlib.h>
#include <assert.h>
#include "04_pointer_handler.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file	*/
	GtkWidget *window = NULL;																							/*	the GUI window					*/
	AppWidgets *widgets = g_slice_new(AppWidgets);
	
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("04_pointer_handler.glade");													/*	load the glade file				*/
	assert(builder != NULL);
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window	*/
	assert(window != NULL);
	
	widgets->text_input = GTK_ENTRY(gtk_builder_get_object(builder, "text_field_input"));
	assert(widgets->text_input != NULL);
	
	widgets->text_output = GTK_ENTRY(gtk_builder_get_object(builder, "text_field_output"));
	assert(widgets->text_output != NULL);
	
	gtk_builder_connect_signals(builder, widgets);																		/*	connect (any) signals			*/
	
	g_object_unref(builder);																							/*	the builder is no longer in use	*/
	gtk_widget_show(window);																							/*	show the window on screen		*/
	gtk_main();																											/*	run application					*/
	
	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}

/**	Whenever the 'X' of the window has been pressed, the window will close
 * 	and the application is going to terminate, too.
*/
void on_main_window_destroy(void) {
	gtk_main_quit();
}

/**	Whenever the button has been pressed, the content of
 * 	the first text field is going to transpose to
 * 	the output text field.
*/
void on_btn_transmit_clicked(GtkButton *button, AppWidgets *widgets) {
	gtk_entry_set_text(widgets->text_output, gtk_entry_get_text(widgets->text_input));
	gtk_entry_set_text(widgets->text_input, "");
}
