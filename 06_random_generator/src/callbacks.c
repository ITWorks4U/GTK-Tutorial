/**
 * 	Contains the callback functions for each widget,
 * 	except for the main window.
*/
#include "../header/random_generator.h"
#include <string.h>

void btn_random_number_clicked_cb(GtkButton *button, struct SRandomStuff *randomized) {
	char numberAsWord[2] = {'\0'};																						/*	holds a number n, ∀ n ∈ {0, 1, ..., 6} as word including \0		*/
	sprintf(numberAsWord, "%d", createRandomNumber());																	/*	convert number to word												*/	
	gtk_entry_set_text(randomized->output_random_number, numberAsWord);
}

void btn_random_label_setting_clicked_cb(GtkButton *button, struct SRandomStuff *randomized) {
	enum EColors colorToUse = selectRandomColorType(createRandomNumber());
	char randomWord[11] = {'\0'};																						/*	holds a word with 10 characters including \0				*/	
	strncpy(randomWord, createRandomWord(), 10);																		/*	get a random word right now									*/
	gchar colorToSet[7] = {'\0'};																						/*	gchar := typedef char gchar; you may also use a char only	*/
	
	switch(colorToUse) {																								/*	select which label color is in use							*/		
		case RED:
			strncpy(colorToSet, COLOR_RED, sizeof(COLOR_RED));
			break;
		case YELLOW:
			strncpy(colorToSet, COLOR_YELLOW, sizeof(COLOR_YELLOW));
			break;
		case GREEN:
			strncpy(colorToSet, COLOR_GREEN, sizeof(COLOR_GREEN));
			break;
		case BLUE:
			strncpy(colorToSet, COLOR_BLUE, sizeof(COLOR_BLUE));
			break;
		case BROWN:
			strncpy(colorToSet, COLOR_BROWN, sizeof(COLOR_BROWN));
			break;
		case PURPLE:
			strncpy(colorToSet, COLOR_PURPLE, sizeof(COLOR_PURPLE));
			break;
		case PINK:
			strncpy(colorToSet, COLOR_PINK, sizeof(COLOR_PINK));
			break;
	}
	
	gchar colorCode[100] = "<span foreground='";																		/*	contains a CSS code instruction								*/
	const gchar colorCodeMiddle[] = "' weight='bold' font='16'>";														/*	the text will have a bold style and a font size of 16		*/
	const gchar colorCodeTail[] = "</span>";
	
	strncat(colorCode, colorToSet, sizeof(colorToSet));																	/*	adding color												*/
	strncat(colorCode, colorCodeMiddle, sizeof(colorCodeMiddle));														/*	adding font weight, too										*/
	strncat(colorCode, randomWord, sizeof(randomWord));																	/*	appending the random word with 10 characters				*/
	strncat(colorCode, colorCodeTail, sizeof(colorCodeTail));
	
	//g_print(colorCode, "%s");																							/*	print the CSS code; the function call below is required		*/
	//g_print("\n");																									/*	otherwise the next code is going to print to the same line	*/
	
	gtk_label_set_markup(GTK_LABEL(randomized->label_color), colorCode);
}
