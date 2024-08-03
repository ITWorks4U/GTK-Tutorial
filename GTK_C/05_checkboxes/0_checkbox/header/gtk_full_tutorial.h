#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>
#include <stdbool.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	IS_TOGGLED			"The check box button is pressed."
#define	IS_NOT_TOGGLED		"The check box button is unpressed."

/*	structures	*/
typedef struct GtkObjects {
	GtkLabel *lbl_status;
	GtkCheckButton *chk_toggle;
}AppWidgets;

#endif