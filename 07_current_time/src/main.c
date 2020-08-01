#include <gtk/gtk.h>

struct STimer {
	GtkEntry *current_time;
};

gboolean systemTimeEvent(struct STimer *timer);

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file				*/
	GtkWidget *window = NULL;																							/*	the GUI window								*/
	
	/*	---	structure to use ---	*/
	struct STimer *timer = g_slice_new(struct STimer);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/07_time_widget.glade");													/*	load the glade file							*/	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window				*/
	
	/*	---	initialize widgets	---	*/
	timer->current_time = GTK_ENTRY(gtk_builder_get_object(builder, "txt_time"));

	/*	---	connect signals to the builder	---	*/
	gtk_builder_connect_signals(builder, timer);
	
	g_object_unref(builder);																							/*	the builder is no longer in use				*/	
	g_timeout_add_seconds(1, (GSourceFunc) systemTimeEvent, timer);	
	
	gtk_widget_show(window);																							/*	show the window on screen					*/
	gtk_main();																											/*	run application								*/
	
	/*	---	release allocated memory ---		*/
	g_slice_free(struct STimer, timer);
	
	return EXIT_SUCCESS;
}

/**	Closes the application.	*/
void on_main_window_destroy(void) {
	gtk_main_quit();
}

gboolean systemTimeEvent(struct STimer *timer) {
	GDateTime *dateTime = NULL;	
	gchar *dateTimeFormatter = NULL;
	
	dateTime = g_date_time_new_now_local();
	dateTimeFormatter = g_date_time_format(dateTime, "%H:%M:%S");
	
	gtk_entry_set_text(timer->current_time, dateTimeFormatter);
	g_free(dateTimeFormatter);
	
	return TRUE;
}
