#include "../header/widgets.h"
#include "../header/names.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file	*/
	GtkWidget *window = NULL;																							/*	the GUI window					*/
	/*	---	structures to use ---	*/
	WidgetsToggle *toggle = g_slice_new(WidgetsToggle);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/all_toggle_buttons.glade");												/*	load the glade file				*/
	assert(builder != NULL);
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window	*/
	assert(window != NULL);
	
	/*	---	initialize widgets	---	*/
	initializeWidgets(toggle, builder);
		
	/*	connect signals to the builder	*/
	gtk_builder_connect_signals(builder, toggle);
	
	g_object_unref(builder);																							/*	the builder is no longer in use	*/
	gtk_widget_show(window);																							/*	show the window on screen		*/
	gtk_main();																											/*	run application					*/
	
	/*	---	release allocated memory ---		*/
	g_slice_free(WidgetsToggle, toggle);
	
	return EXIT_SUCCESS;
}

/**	Closes the application.	*/
void main_window_destroy_cb(void) {
	gtk_main_quit();
}

/*	→ given macros below are defined in names.h ←	*/
void initializeWidgets(WidgetsToggle *toggle, GtkBuilder *builderToUse) {
	toggle->tgl_btn = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builderToUse, TOGGLE_BUTTON_NAME));
	toggle->lbl_tgl_output = GTK_LABEL(gtk_builder_get_object(builderToUse, LABEL_TOGGLED_NAME));
	
	toggle->chk_btn_1 = GTK_CHECK_BUTTON(gtk_builder_get_object(builderToUse, CHECK_BUTTON_1_NAME));
	toggle->chk_btn_2 = GTK_CHECK_BUTTON(gtk_builder_get_object(builderToUse, CHECK_BUTTON_2_NAME));
	toggle->chk_btn_3 = GTK_CHECK_BUTTON(gtk_builder_get_object(builderToUse, CHECK_BUTTON_3_NAME));
	toggle->lbl_check_box_output = GTK_LABEL(gtk_builder_get_object(builderToUse, LABEL_CHECKED_NAME));
	
	toggle->radio_button_0 = GTK_RADIO_BUTTON(gtk_builder_get_object(builderToUse, RADIO_BUTTON_0_NAME));
	toggle->radio_button_1 = GTK_RADIO_BUTTON(gtk_builder_get_object(builderToUse, RADIO_BUTTON_1_NAME));
	toggle->radio_button_2 = GTK_RADIO_BUTTON(gtk_builder_get_object(builderToUse, RADIO_BUTTON_2_NAME));
	toggle->lbl_radio_button_output = GTK_LABEL(gtk_builder_get_object(builderToUse, LABEL_RADIO_NAME));
}
