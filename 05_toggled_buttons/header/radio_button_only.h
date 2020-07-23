#ifndef RADIO_BUTTON_ONLY_H
#define RADIO_BUTTON_ONLY_H

#include <gtk/gtk.h>

struct SRadioButton {
	GtkRadioButton *rb_01;
	GtkRadioButton *rb_02;
	GtkRadioButton *rb_03;
	GtkLabel *lbl_for_radio_buttons;
};

#define	NAME_RB_01				"rb_01"
#define	NAME_RB_02				"rb_02"
#define	NAME_RB_03				"rb_03"
#define NAME_LABEL_RB_BUTTON	"lbl_for_radio_buttons"

#endif
