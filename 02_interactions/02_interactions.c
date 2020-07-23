#include <gtk/gtk.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define	STRING_LENGTH	64
#define	STRING_CLICKED	"You've clicked this button "
#define	STRING_TAIL		" times."

GtkWidget *g_lbl_clicked = NULL;

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file	*/
	GtkWidget *window = NULL;																							/*	the GUI window					*/
	
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("02_interactions.glade");														/*	load the glade file				*/
	assert(builder != NULL);
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window	*/
	assert(window != NULL);
	
	gtk_builder_connect_signals(builder, NULL);																			/*	connect (any) signals			*/
	g_lbl_clicked = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_clicked"));
	
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

/**	Whenever the button has been pressed, the nested counter
 * 	raises by one and the result is going to print to the label.
*/
void on_btn_to_click_clicked(void) {
	static unsigned int count = 0;
	char strCounter[STRING_LENGTH] = {'\0'};
	char strClicked[4] = {'\0'};
	
	strncpy(strCounter, STRING_CLICKED, strlen(STRING_CLICKED));
	count++;
	
	sprintf(strClicked, "%d", count);
	
	strncat(strCounter, strClicked, strlen(strClicked));
	strncat(strCounter, STRING_TAIL, strlen(STRING_TAIL));
	
	gtk_label_set_text(GTK_LABEL(g_lbl_clicked), strCounter);
}
