/**
 * 	Contains the main function only.
*/
#include "../header/random_generator.h"
#include <stdlib.h>

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file	*/
	GtkWidget *window = NULL;																							/*	the GUI window					*/
	
	/*	---	structure to use ---	*/
	struct SRandomStuff *randomized = g_slice_new(struct SRandomStuff);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/06_random_generator_pattern.glade");										/*	load the glade file				*/	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window	*/
	
	/*	---	initialize widgets	---	*/
	randomized->button_random_number = GTK_BUTTON(gtk_builder_get_object(builder, "btn_random_number"));
	randomized->output_random_number = GTK_ENTRY(gtk_builder_get_object(builder, "txt_random"));
	randomized->button_label_color = GTK_BUTTON(gtk_builder_get_object(builder, "btn_random_label_setting"));
	randomized->label_color = GTK_LABEL(gtk_builder_get_object(builder, "lbl_random"));

	/*	---	connect signals to the builder	---	*/
	gtk_builder_connect_signals(builder, randomized);
	
	g_object_unref(builder);																							/*	the builder is no longer in use	*/
	gtk_widget_show(window);																							/*	show the window on screen		*/
	gtk_main();																											/*	run application					*/
	
	/*	---	release allocated memory ---		*/
	g_slice_free(struct SRandomStuff, randomized);
	
	return EXIT_SUCCESS;
}

/**	Closes the application.	*/
void main_window_destroy_cb(void) {
	gtk_main_quit();
}
