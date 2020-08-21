#ifndef FILECHOOSER_H
#define FILECHOOSER_H

#include <gtk/gtk.h>

struct SFileChooserExample {
	GtkTextView *text_view_area;																						/*	pointer to text view object					*/
	GtkFileChooserDialog *w_dlg_file_choose;																			/*	pointer to file choose dialog				*/
	GtkTextBuffer *textbuffer_main;																						/*	pointer to text buffer						*/
	
	GtkFileChooserDialog *w_dlg_save_file;																				/*	pointer to file save dialog					*/
	
	GtkAboutDialog *aboutDialog;																						/*	pointer to about dialog						*/
};

typedef enum {																											/*	optional: a filter system for file dialog	*/
	ALL_TEXT_FILES = 0,
	TEXT_FILES = 0x00001,
	C_SOURCE_FILES = 0x00010,
	CPP_SOURCE_FILES = 0x00100,
	JAVA_SOURCE_FILES = 0x01000,
	PYTHON_FILES = 0x10000
} FileFilters;

GtkFileFilter *updateFileFilter(FileFilters filters);

#endif
