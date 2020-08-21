#include "../header/fileChooser.h"

void menu_open_activate_cb(GtkMenuItem *menuItem, struct SFileChooserExample *fce) {
	gchar *fileName = NULL;																								/*	name of the file to use			*/
	gchar *fileContents = NULL;																							/*	for reading contents of file	*/
	gboolean fileSuccess = FALSE;																						/*	file read status				*/
	
	GtkFileFilter *fileFilter = NULL;																					/*	create an own file filer		*/
	fileFilter = updateFileFilter(TEXT_FILES | C_SOURCE_FILES);															/*	uses *c, *h, *.txt files only	*/
	gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(fce->w_dlg_file_choose), fileFilter);									/*	and update the file dialog		*/
	
	gtk_widget_show(GTK_WIDGET(fce->w_dlg_file_choose));																/*	show the "open text file" dialog box	*/
	
	if (gtk_dialog_run(GTK_DIALOG(fce->w_dlg_file_choose)) == GTK_RESPONSE_OK) {										/*	check return value from open text file dialog */
		fileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fce->w_dlg_file_choose));
		
		if (fileName != NULL) {
			fileSuccess = g_file_get_contents(fileName, &fileContents, NULL, NULL);										/*	copy the contents of the file to dynamically allocated memory	*/
			
			if (fileSuccess) {
				gtk_text_buffer_set_text(fce->textbuffer_main, fileContents, -1);
			}
			
			g_free(fileContents);
		}
		
		g_free(fileName);
	}
	
	gtk_widget_hide(GTK_WIDGET(fce->w_dlg_file_choose));																/*	finished with the dialog -> hide the dialog	*/
}

void menu_save_activate_cb(GtkMenuItem *menuItem, struct SFileChooserExample *fce) {
	gchar *fileName = NULL;
	gchar *textContent = NULL;
	
	GtkFileFilter *filterForSaving = NULL;
	filterForSaving = updateFileFilter(ALL_TEXT_FILES);
	gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(fce->w_dlg_save_file), filterForSaving);
	
	gtk_widget_show(GTK_WIDGET(fce->w_dlg_save_file));
	
	if (gtk_dialog_run(GTK_DIALOG(fce->w_dlg_save_file)) == GTK_RESPONSE_OK) {
		fileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fce->w_dlg_save_file));
		
		GtkTextIter *start = (GtkTextIter *) calloc(1, sizeof(GtkTextIter));
		GtkTextIter *end = (GtkTextIter *) calloc(1, sizeof(GtkTextIter));
		
		gtk_text_buffer_get_start_iter(fce->textbuffer_main, start);
		gtk_text_buffer_get_end_iter(fce->textbuffer_main, end);
		
		if (fileName != NULL) {
			textContent = gtk_text_buffer_get_text(fce->textbuffer_main, start, end, -1);
			g_file_set_contents(fileName, textContent, strlen(textContent), NULL);
			
			g_free(textContent);
		}
		
		g_free(end);
		g_free(start);
		g_free(fileName);
	}
	
	gtk_widget_hide(GTK_WIDGET(fce->w_dlg_save_file));
}

void menu_quit_activate_cb(GtkMenuItem *menuItem, struct SFileChooserExample *fce) {
	gtk_main_quit();
}

void menu_about_activate_cb(GtkMenuItem *menuItem, struct SFileChooserExample *fce) {
	gtk_widget_show(GTK_WIDGET(fce->aboutDialog));
}

void dlg_box_about_close_cb(GtkDialog *dialog, struct SFileChooserExample *fce) {
	gtk_widget_hide(GTK_WIDGET(fce->aboutDialog));
}

GtkFileFilter *updateFileFilter(FileFilters filters) {
	GtkFileFilter *filterToUse = gtk_file_filter_new();
	
	if (filters == ALL_TEXT_FILES) {
		gtk_file_filter_add_pattern(filterToUse, "*.txt");
		gtk_file_filter_add_pattern(filterToUse, "*.c");
		gtk_file_filter_add_pattern(filterToUse, "*.h");
		gtk_file_filter_add_pattern(filterToUse, "*.cpp");
		gtk_file_filter_add_pattern(filterToUse, "*.hpp");
		gtk_file_filter_add_pattern(filterToUse, "*.java");
		gtk_file_filter_add_pattern(filterToUse, "*.py");
		
	} else {	
		if ((filters & TEXT_FILES) == TEXT_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.txt");
		}
		
		if ((filters & C_SOURCE_FILES) == C_SOURCE_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.c");
			gtk_file_filter_add_pattern(filterToUse, "*.h");		
		}
		
		if ((filters & CPP_SOURCE_FILES) == CPP_SOURCE_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.cpp");
			gtk_file_filter_add_pattern(filterToUse, "*.hpp");
			gtk_file_filter_add_pattern(filterToUse, "*.h");
		}
		
		if ((filters & JAVA_SOURCE_FILES) == JAVA_SOURCE_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.java");
		}
		
		if ((filters & PYTHON_FILES) == PYTHON_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.py");
		}
	}
	
	return filterToUse;
}
