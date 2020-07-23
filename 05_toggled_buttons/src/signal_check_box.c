/**	Contains the signal handler for the switch button
 * 	and also for the check boxes.
*/
#include "../header/widgets.h"

void chk_btn_1_toggled_cb(GtkCheckButton *chkBtn, WidgetsToggle *toggle) {
	static int ctr = 0;
	ctr++;
		
	if (ctr % 2 == 0) {																									/*	this check box is not checked	*/
		updateTextForCheckBoxLabel(chkBtn, STATE_UNPRESSED, toggle);
	} else {																											/*	this check box is checked		*/
		updateTextForCheckBoxLabel(chkBtn, STATE_PRESSED, toggle);
	}
}

void chk_btn_2_toggled_cb(GtkCheckButton *chkBtn, WidgetsToggle *toggle) {
	static int ctr = 0;
	ctr++;
	
	if (ctr % 2 == 0) {
		updateTextForCheckBoxLabel(chkBtn, STATE_UNPRESSED, toggle);
	} else {
		updateTextForCheckBoxLabel(chkBtn, STATE_PRESSED, toggle);
	}
}

void chk_btn_3_toggled_cb(GtkCheckButton *chkBtn, WidgetsToggle *toggle) {
	static int ctr = 0;
	ctr++;
	
	if (ctr % 2 == 0) {
		updateTextForCheckBoxLabel(chkBtn, STATE_UNPRESSED, toggle);
	} else {
		updateTextForCheckBoxLabel(chkBtn, STATE_PRESSED, toggle);
	}
}

void updateTextForCheckBoxLabel(GtkCheckButton *button, const char *message, WidgetsToggle *toggle) {
	char allButtons[120] = {'\0'};
	static char infoBox1[40] = {'\0'};
	static char infoBox2[40] = {'\0'};
	static char infoBox3[40] = {'\0'};
	
	if (button == toggle->chk_btn_1) {																					/*	first check box in use (no matter if checked or not)	*/
		if (strcmp(message, STATE_PRESSED) == 0) {																		/*	button is checked	*/
			strcpy(infoBox1, "first box selected\n");
		} else {																										/*	otherwise it's not	*/
			strcpy(infoBox1, "\n");
		}
	}

	if (button == toggle->chk_btn_2) {																					/*	same operations for the second check box	*/
		if (strcmp(message, STATE_PRESSED) == 0) {																		/*	button is checked	*/
			strcpy(infoBox2, "second box selected\n");
		} else {																										/*	otherwise it's not	*/
			strcpy(infoBox2, "\n");
		}
	}

	if (button == toggle->chk_btn_3) {																					/*	also for the third check box	*/
		if (strcmp(message, STATE_PRESSED) == 0) {																		/*	button is checked	*/
			strcpy(infoBox3, "third box selected\n");
		} else {																										/*	otherwise it's not	*/
			strcpy(infoBox3, "\n");
		}
	}
	
	/*	finally, always put all informations together to "allButtons"	*/
	strcpy(allButtons, infoBox1);
	strncat(allButtons, infoBox2, sizeof(infoBox2));
	strncat(allButtons, infoBox3, sizeof(infoBox3));

	/*	transpose the c-string to the label	*/		
	gtk_label_set_text(toggle->lbl_check_box_output, allButtons);
}
