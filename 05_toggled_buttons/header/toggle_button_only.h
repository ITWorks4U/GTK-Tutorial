#ifndef TOGGLE_BUTTON_ONLY_H
#define TOGGLE_BUTTON_ONLY_H

#include <gtk/gtk.h>

struct SToggleButton {
	GtkToggleButton *tgl_button;
	GtkLabel *lbl_for_toggle_button;
};

#define	NAME_TOGGLE_BUTTON	"toggle_button"
#define NAME_LABEL_TOGGLE_BUTTON	"lbl_for_toggle_button"

#endif
