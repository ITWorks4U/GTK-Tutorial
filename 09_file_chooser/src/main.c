#include "../header/fileChooser.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file				*/
	GtkWidget *window = NULL;																							/*	the GUI window								*/
	
	/*	---	structure to use ---	*/
	struct SFileChooserExample *fce = g_slice_new(struct SFileChooserExample);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/09_file_handler_main.glade");											/*	load the glade file							*/	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window				*/
	
	/*	---	initialize widgets	---	*/
	fce->text_view_area = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "text_view_area"));
	fce->w_dlg_file_choose = GTK_FILE_CHOOSER_DIALOG(gtk_builder_get_object(builder, "dlg_file_choose"));
	fce->textbuffer_main = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer1"));
	fce->w_dlg_save_file = GTK_FILE_CHOOSER_DIALOG(gtk_builder_get_object(builder, "dlg_file_save"));
	fce->aboutDialog = GTK_ABOUT_DIALOG(gtk_builder_get_object(builder, "dlg_box_about"));
	
	/*	---	connect signals to the builder	---	*/
	gtk_builder_connect_signals(builder, fce);
	
	g_object_unref(builder);																							/*	the builder is no longer in use				*/
	gtk_widget_show(window);																							/*	show the window on screen					*/
	gtk_main();																											/*	run application								*/
		
	/*	---	release allocated memory ---		*/
	g_slice_free(struct SFileChooserExample, fce);
	
	return EXIT_SUCCESS;
}

/**	Closes the application.	*/
void main_window_destroy_cb(void) {
	gtk_main_quit();
}
