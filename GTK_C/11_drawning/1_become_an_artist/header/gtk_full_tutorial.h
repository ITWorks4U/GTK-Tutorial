#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"

/*	structures	*/
typedef struct GtkObjects {
	GtkDrawingArea *area_to_draw;
}AppWidgets;

extern cairo_surface_t *surface;

void clear_surface(void);
void draw_brush(GtkWidget *widget, gdouble x, gdouble y);

#endif