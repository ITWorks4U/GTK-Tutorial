#include "../header/image_viewer.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file				*/
	GtkWidget *window = NULL;																							/*	the GUI window								*/
	
	/*	---	structure to use ---	*/
	struct SImageViewer *siv = g_slice_new(struct SImageViewer);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/10_image_viewer.glade");													/*	load the glade file							*/	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window				*/
	
	/*	---	initialize widgets	---	*/
	siv->btn_image_viewer = GTK_BUTTON(gtk_builder_get_object(builder, "btn_picture"));
	siv->w_img_main = GTK_IMAGE(gtk_builder_get_object(builder, "img_main"));
	siv->w_dlg_file_name = GTK_FILE_CHOOSER_DIALOG(gtk_builder_get_object(builder, "dlg_file_choose"));
	
	/*	---	connect signals to the builder	---	*/
	gtk_builder_connect_signals(builder, siv);
	
	g_object_unref(builder);																							/*	the builder is no longer in use				*/
	gtk_widget_show(window);																							/*	show the window on screen					*/
	gtk_main();																											/*	run application								*/
		
	/*	---	release allocated memory ---		*/
	g_slice_free(struct SImageViewer, siv);
	
	return EXIT_SUCCESS;
}

/**	Closes the application.	*/
void on_main_window_destroy(void) {
	gtk_main_quit();
}

