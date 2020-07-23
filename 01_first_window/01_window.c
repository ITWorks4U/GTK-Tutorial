#include <gtk/gtk.h>

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWidget *window = NULL;
	
	gtk_init(&argc, &argv);
	
	//	old version
	//~ builder = gtk_builder_new();
	//~ gtk_builder_add_from_file(builder, "01_first_window.glade", NULL);
	
	//	new version
	builder = gtk_builder_new_from_file("01_first_window.glade");
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
	
	gtk_widget_show(window);
	gtk_main();
	
	return 0;
}

void on_main_window_destroy(void) {
	gtk_main_quit();
}
