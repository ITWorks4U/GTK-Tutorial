#include "../header/checkbox_button_only.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWidget *window = NULL;
	
	/*	---	structure to use ---	*/
	struct SCheckBoxButton *checkBoxes = g_slice_new(struct SCheckBoxButton);
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file("glade/check_box_buttons.glade");	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	
	/*	---	initialize widgets	---	*/
	checkBoxes->check_button_01 = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, NAME_CHECK_01));
	checkBoxes->check_button_02 = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, NAME_CHECK_02));
	checkBoxes->check_button_03 = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, NAME_CHECK_03));
	checkBoxes->lbl_for_check_buttons = GTK_LABEL(gtk_builder_get_object(builder, NAME_LABEL_CHECK_BUTTON));
		
	/*	connect signals to the builder	*/
	gtk_builder_connect_signals(builder, checkBoxes);
	
	g_object_unref(builder);
	gtk_widget_show(window);
	gtk_main();
	
	/*	---	release allocated memory ---		*/
	g_slice_free(struct SCheckBoxButton, checkBoxes);
	
	return EXIT_SUCCESS;
}

/*	event handler for window	*/
void main_window_destroy_cb(void) {
	gtk_main_quit();
}

/*	event for check buttons activity	*/
void check_01_toggled_cb(GtkCheckButton *chkBtn, struct SCheckBoxButton *checkBox) {
	static int ctr = 0;
	ctr++;
	
	if (ctr % 2 == 0) {
		updateTextForCheckBoxLabel(chkBtn, STATE_UNPRESSED, checkBox);
	} else {
		updateTextForCheckBoxLabel(chkBtn, STATE_PRESSED, checkBox);
	}
}

void check_02_toggled_cb(GtkCheckButton *chkBtn, struct SCheckBoxButton *checkBox) {
	static int ctr = 0;
	ctr++;
	
	if (ctr % 2 == 0) {
		updateTextForCheckBoxLabel(chkBtn, STATE_UNPRESSED, checkBox);
	} else {
		updateTextForCheckBoxLabel(chkBtn, STATE_PRESSED, checkBox);
	}
}

void check_03_toggled_cb(GtkCheckButton *chkBtn, struct SCheckBoxButton *checkBox) {
	static int ctr = 0;
	ctr++;
	
	if (ctr % 2 == 0) {
		updateTextForCheckBoxLabel(chkBtn, STATE_UNPRESSED, checkBox);
	} else {
		updateTextForCheckBoxLabel(chkBtn, STATE_PRESSED, checkBox);
	}
}

void updateTextForCheckBoxLabel(GtkCheckButton *button, const char *message, struct SCheckBoxButton *checkBox) {
	char allButtons[120] = {'\0'};
	static char infoBox1[40] = {'\0'};
	static char infoBox2[40] = {'\0'};
	static char infoBox3[40] = {'\0'};
	
	if (button == checkBox->check_button_01) {
		if (strcmp(message, STATE_PRESSED) == 0) {
			strcpy(infoBox1, "first box selected\n");
		} else {
			strcpy(infoBox1, "\n");
		}
	}
	
	if (button == checkBox->check_button_02) {
		if (strcmp(message, STATE_PRESSED) == 0) {
			strcpy(infoBox2, "second box selected\n");
		} else {
			strcpy(infoBox2, "\n");
		}
	}
	
	if (button == checkBox->check_button_03) {
		if (strcmp(message, STATE_PRESSED) == 0) {
			strcpy(infoBox3, "third box selected\n");
		} else {
			strcpy(infoBox3, "\n");
		}		
	}
	
	strcpy(allButtons, infoBox1);
	strncat(allButtons, infoBox2, sizeof(infoBox2));
	strncat(allButtons, infoBox3, sizeof(infoBox3));
	
	gtk_label_set_text(checkBox->lbl_for_check_buttons, allButtons);
}
