#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEVER_H

#include <gtk/gtk.h>

struct SImageViewer {
	GtkImage *w_img_main;																								/*	pointer for image								*/
	GtkFileChooserDialog *w_dlg_file_name;																				/*	pointer to file chooser							*/
	GtkButton *btn_image_viewer;																						/*	pointer for the button							*/
};

#endif
