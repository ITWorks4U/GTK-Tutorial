#include "../header/image_viewer.h"
#include <stdio.h>
#include <stdlib.h>

/*	open and load a picture	*/
void on_btn_picture_clicked(GtkButton *btnImage, struct SImageViewer *siv) {
	gchar *file_name = NULL;
	gtk_widget_show(GTK_WIDGET(siv->w_dlg_file_name));																	/*	open file chooser						*/
	
	if (gtk_dialog_run(GTK_DIALOG(siv->w_dlg_file_name)) == GTK_RESPONSE_OK) {											/*	check the returning value				*/
		file_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(siv->w_dlg_file_name));								/*	get the file name from the dialog box	*/
		g_assert(file_name != NULL);
		g_print("%s\n", file_name);
		
		gtk_image_set_from_file(GTK_IMAGE(siv->w_img_main), file_name);
	}
	
	g_free(file_name);
	gtk_widget_hide(GTK_WIDGET(siv->w_dlg_file_name));																	/*	close file chooser						*/	
}
