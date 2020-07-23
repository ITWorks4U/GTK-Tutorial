/**
 * 	Contains structures for the given listening no. 5.
*/

#ifndef WIDGETS_H
#define WIDGETS_H

#include <gtk/gtk.h>
#include <string.h>

/* 	---------------------------
 * 	We may use one struct only, because the gtk function
 * 	"gtk_builder_connect_signals" can register a single struct only.
 * 
 * 	It's not possible to register more than one. If we do this, then
 * 	the application writes assertion errors on the terminal at runtime
 *	for uninitialized widgets.
 * 	---------------------------
*/

/*	required widgets for the application	*/
typedef struct SWidgetsToggle {	
	/*	---	toggle button	---	*/
	GtkToggleButton *tgl_btn;
	GtkLabel *lbl_tgl_output;
	
	/*	---	check boxes		---	*/
	GtkCheckButton *chk_btn_1;
	GtkCheckButton *chk_btn_2;
	GtkCheckButton *chk_btn_3;
	GtkLabel *lbl_check_box_output;
	
	/*	---	radio buttons	---	*/
	GtkRadioButton *radio_button_0;
	GtkRadioButton *radio_button_1;
	GtkRadioButton *radio_button_2;
	GtkLabel *lbl_radio_button_output;
} WidgetsToggle;

/*			---	functions to use ---			*/
void initializeWidgets(WidgetsToggle *toggle, GtkBuilder *builderToUse);
void updateTextForCheckBoxLabel(GtkCheckButton *button, const char *message, WidgetsToggle *toggle);

/*	definition of statements (check boxes only)		*/
#define	STATE_PRESSED		"PRESSED"
#define	STATE_UNPRESSED		"UNPRESSED"

#endif
