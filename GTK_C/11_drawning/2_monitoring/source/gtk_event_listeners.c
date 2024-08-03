#include "../header/gtk_full_tutorial.h"
#include <stdbool.h>

void window_destroy(void) {
	gtk_main_quit();
}

void init_cpu_array(void) {
	for (int i = 0; i < BUFFER; i++) {
		cpu[i] = 0;
	}
}

gboolean timer_handler(AppWidgets *app) {
	static long time_start = 0, time_end = 0;
	static bool flag = false;

	char line[BUFF128];
	char tmp[(BUFF128/4)];

	memset(line, '\0', BUFF128);
	memset(tmp, '\0', (BUFF128/4));

	FILE *fp = NULL;

	if ((fp = fopen("/proc/stat", "r")) == NULL) {
		return FALSE;
	}

	fgets(line, BUFF128, fp);
	fclose(fp);

	sscanf(line, "%s %ld", tmp, &time_end);

	if (!flag) {
		flag = true;
		time_start = time_end;
		return TRUE;
	}

	cpu_util = time_end - time_start;
	for(int i = BUFFER-1; i > 0; i--) {
		cpu[i] = cpu[i-1];
	}

	cpu[0] = cpu_util/2;

	char cpu_percentage[TINY_BUFFER];
	memset(cpu_percentage, '\0', TINY_BUFFER);
	sprintf(cpu_percentage, "%d%%", cpu_util);

	gtk_label_set_text(app->lbl_cpu_optimization, cpu_percentage);

	time_start = time_end;
	gtk_widget_queue_draw(GTK_WIDGET(app->area_to_draw));

	return TRUE;
}

gboolean draw_cpu_line(AppWidgets *app, cairo_t *cr, gpointer data) {
	cairo_set_line_width(cr, 2.0);

	for(int i = 0; i < BUFFER; i++) {
		cairo_set_source_rgb(cr, 1.0, 0.1, 0.3);
		cairo_move_to(cr, (double) ((i * 4) + 10), (double) (2 * (BUFFER*2 - cpu[i]) + 10));
		cairo_line_to(cr, (double) (((i+1) * 4) + 10), (double)(2 * (BUFFER*2 - cpu[i + 1]) + 10));
		cairo_stroke(cr);
	}

	return TRUE;
}