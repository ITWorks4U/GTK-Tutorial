#include <gtk/gtk.h>
#include <string.h>

struct SSelectButtons {
	GtkComboBoxText *comboBox;
	GtkLabel *output;
	GtkButton *btnTest;
	
	GtkSpinButton *spinButton;
};

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;																							/*	builder to load the glade file				*/
	GtkWidget *window = NULL;																							/*	the GUI window								*/
	
	/*	---	structure to use ---	*/
	struct SSelectButtons *boxTester = g_slice_new(struct SSelectButtons);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/08_select_buttons.glade");												/*	load the glade file							*/	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));												/*	connect builder with the window				*/
	
	/*	---	initialize widgets	---	*/
	boxTester->comboBox = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "combo_box_text"));
	boxTester->output = GTK_LABEL(gtk_builder_get_object(builder, "lbl_output"));
	boxTester->btnTest = GTK_BUTTON(gtk_builder_get_object(builder, "btn_add"));
	
	boxTester->spinButton = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spin_button"));

	/*	---	connect signals to the builder	---	*/
	gtk_builder_connect_signals(builder, boxTester);
	
	g_object_unref(builder);																							/*	the builder is no longer in use				*/
	gtk_widget_show(window);																							/*	show the window on screen					*/
	gtk_main();																											/*	run application								*/
	
	/*	---	release allocated memory ---		*/
	g_slice_free(struct SSelectButtons, boxTester);
	
	return EXIT_SUCCESS;
}

/**	Closes the application.	*/
void main_window_destroy_cb(void) {
	gtk_main_quit();
}

void combo_box_text_changed_cb(GtkComboBoxText *comboBoxText, struct SSelectButtons *boxTester) {	
	gchar *itemText = gtk_combo_box_text_get_active_text(boxTester->comboBox);
	gtk_label_set_text(boxTester->output, itemText);
	g_free(itemText);
}

void btn_add_clicked_cb(GtkButton *button, struct SSelectButtons *boxTester) {
	static gint itemNumber = 4;
	gchar itemNumberAsWord[3] = {'\0'};
	gchar newItem[20] = "new added item: ";
	
	sprintf(itemNumberAsWord, "%u", itemNumber);
	strncat(newItem, itemNumberAsWord, strlen(itemNumberAsWord));
	
	itemNumber++;
	gtk_combo_box_text_insert_text(boxTester->comboBox, itemNumber, newItem);
}

void spin_button_value_changed_cb(GtkSpinButton *spin_button, struct SSelectButtons *boxTester) {	
	gint spinNumber = gtk_spin_button_get_value_as_int(boxTester->spinButton);
	gchar spinNumberAsWord[4] = {'\0'};
	sprintf(spinNumberAsWord, "%u", spinNumber);
	
	gtk_label_set_text(boxTester->output, spinNumberAsWord);	
}
