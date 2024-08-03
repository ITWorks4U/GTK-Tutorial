#include "../header/gtk_full_tutorial.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;
	AppWidgets *widgets = g_slice_new(AppWidgets);

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file(GLADE_SOURCE_PATH);

	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	widgets->area_to_draw = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "draw_area"));
	widgets->lbl_cpu_optimization = GTK_LABEL(gtk_builder_get_object(builder, "cpu_optimization_level"));

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	g_timeout_add_seconds(1, (GSourceFunc)timer_handler, widgets);
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}