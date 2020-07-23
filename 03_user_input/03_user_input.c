#include <gtk/gtk.h>
#include <stdlib.h>
#include <assert.h>

GtkEntry *text_input = NULL;

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file	*/
	GtkWidget *window = NULL;																							/*	the GUI window					*/
	
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("03_user_input.glade");															/*	load the glade file				*/
	assert(builder != NULL);
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window	*/
	assert(window != NULL);
	
	text_input = GTK_ENTRY(gtk_builder_get_object(builder, "text_field_input"));
	assert(text_input != NULL);
	
	gtk_builder_connect_signals(builder, NULL);																			/*	connect (any) signals			*/
	
	g_object_unref(builder);																							/*	the builder is no longer in use	*/
	gtk_widget_show(window);																							/*	show the window on screen		*/
	gtk_main();																											/*	run application					*/
	
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
void on_btn_transmit_clicked(GtkButton *button, GtkEntry *output) {
	gtk_entry_set_text(output, gtk_entry_get_text(text_input));
	gtk_entry_set_text(text_input, "");
}
