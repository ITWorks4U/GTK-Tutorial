#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	BUFFER				50
#define	BUFF128				128
#define	TINY_BUFFER			10

/*	structures	*/
typedef struct GtkObjects {
	GtkDrawingArea *area_to_draw;
	GtkLabel *lbl_cpu_optimization;
}AppWidgets;

/*	function prototypes	*/
gboolean timer_handler(AppWidgets *app);
void init_cpu_array(void);

/*	external definitions	*/
extern int cpu_util;
extern int cpu[BUFFER];

#endif
