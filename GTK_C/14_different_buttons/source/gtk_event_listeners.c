#include "../header/gtk_full_tutorial.h"
#include <string.h>

void window_destroy(void) {
	gtk_main_quit();
}

void event_for_button(GtkButton *btn, AppWidgets *app) {
	gtk_label_set_text(app->lbl_normal_button, "normal button pressed");
}

void event_for_spin_button(GtkSpinButton *btn, AppWidgets *app) {
	gdouble received_value = gtk_spin_button_get_value(app->spin_btn);
	char tmp[BUFFER];
	memset(tmp, '\0', BUFFER);

	sprintf(tmp, "%lf", received_value);
	gtk_label_set_text(app->lbl_spin_button, tmp);
}

void event_for_toggle_button(GtkToggleButton *btn, AppWidgets *app) {
	static int ctr = 0;
	ctr++;

	if (ctr % 2 == 1) {
		gtk_label_set_text(app->lbl_toggle_button, "toggle button pressed");
	} else {
		gtk_label_set_text(app->lbl_toggle_button, "toggle button unpressed");
	}
}

void event_for_menu_button(GtkMenuButton *btn, AppWidgets *app) {
	static int ctr = 0;
	ctr++;

	if (ctr % 2 == 1) {
		gtk_label_set_text(app->lbl_menu_button, "menu button pressed");
	} else {
		gtk_label_set_text(app->lbl_menu_button, "menu button unpressed");
	}
}

void event_for_lock_button(GtkLockButton *btn, AppWidgets *app) {
	static int ctr = 0;
	ctr++;

	if (ctr % 2 == 1) {
		gtk_label_set_text(app->lbl_lock_button, "lock button pressed");
	} else {
		gtk_label_set_text(app->lbl_lock_button, "lock button unpressed");
	}
}

void event_for_switch_button(GtkSwitch *btn, AppWidgets *app) {
	/*
		!!!	In this version the event for a GtkSwitch causes a segmentation fault,
		due an "invalid cast from 'GtkModelButton' to 'GtkFileChooserButton'" !!!
	*/
	// gboolean state = gtk_switch_get_state(app->btn_switch);

	// if (state) {
	// 	gtk_label_set_text(app->lbl_switch_button, "switch button ON");
	// } else {
	// 	gtk_label_set_text(app->lbl_switch_button, "switch button OFF");
	// }
}

void event_for_model_button(GtkModelButton *btn, AppWidgets *app) {
	gtk_label_set_text(app->lbl_model_button, "model button pressed");
}

void event_for_chosen_file(GtkFileChooserButton *btn, AppWidgets *app) {
	gint nbr_of_chars = gtk_file_chooser_button_get_width_chars(app->file_chooser_button);
	char tmp[BUFFER];
	memset(tmp, '\0', BUFFER);
	sprintf(tmp, "%d", nbr_of_chars);

	gtk_label_set_text(app->lbl_file_chooser_button, tmp);
}

void event_for_chosen_color(GtkColorButton *btn, AppWidgets *app) {
	GdkRGBA color;
	
	/*	deprecated	*/
	//gtk_color_button_get_rgba(app->color_btn, &color);
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(app->color_btn), &color);

	char tmp[BUFFER];
	memset(tmp, '\0', BUFFER);
	sprintf(tmp, "red: %.2lf, green: %.2lf, blue: %.2lf, alpha: %.2lf", color.red, color.green, color.blue, color.alpha);

	gtk_label_set_text(app->lbl_color_chooser_button, tmp);
}

void event_for_chosen_font(GtkFontButton *btn, AppWidgets *app) {
	/*	deprecated	*/
	// gtk_font_button_get_font_name(app->font_button);
	

	gtk_label_set_text(app->lbl_font_button, gtk_font_chooser_get_font(GTK_FONT_CHOOSER(app->font_button)));
}

void event_link_button(GtkLinkButton *btn, AppWidgets *app) {
	gtk_label_set_text(app->lbl_link_button, gtk_link_button_get_uri(app->link_btn));
}

void event_for_scale_button(GtkScaleButton *btn, AppWidgets *app) {
	gdouble value = gtk_scale_button_get_value(app->scale_btn);
	char tmp[BUFFER];
	memset(tmp, '\0', BUFFER);
	sprintf(tmp, "%.2lf", value);

	gtk_label_set_text(app->lbl_scale_button, tmp);
}

void event_for_volume_button(GtkVolumeButton *btn, AppWidgets *app) {
	/*	see:	GtkScaleButton	*/

	gdouble value = gtk_scale_button_get_value(GTK_SCALE_BUTTON(app->volume_btn));
	char tmp[BUFFER];
	memset(tmp, '\0', BUFFER);
	sprintf(tmp, "%.2lf", value);

	gtk_label_set_text(app->lbl_volume_button, tmp);
}

void event_for_chooser_button(GtkAppChooserButton *btn, AppWidgets *app) {
	/*	does nothing here; maybe an implementation is missing?	*/
	gtk_label_set_text(app->lbl_app_chooser_button, gtk_app_chooser_button_get_heading(app->app_btn));
}