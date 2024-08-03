#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void clear_surface(void) {
	cairo_t *cr = cairo_create(surface);
	cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
	cairo_paint(cr);
	cairo_destroy(cr);
}

void draw_brush(GtkWidget *widget, gdouble x, gdouble y) {
	cairo_t *cr = cairo_create(surface);
	cairo_rectangle(cr, x, y, 10.0, 10.0);
	cairo_fill(cr);
	cairo_destroy(cr);

	gtk_widget_queue_draw_area(widget, x, y, 10.0, 10.0);
}

gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer data) {
	if (surface != NULL) {
		cairo_surface_destroy(surface);
	}

	surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget), CAIRO_CONTENT_COLOR, gtk_widget_get_allocated_width(widget), gtk_widget_get_allocated_height(widget));
	clear_surface();

	return TRUE;
}

gboolean draw_something(GtkWidget *widget, cairo_t *cr, gpointer data) {
	cairo_set_source_surface(cr, surface, 0.0, 0.0);
	cairo_paint(cr);

	return TRUE;
}

gboolean button_press_event_cb(GtkWidget *widget, GdkEventButton *event, gpointer data) {
	if (surface == NULL) {
		return FALSE;
	}

	if (event->button == GDK_BUTTON_PRIMARY) {
		draw_brush(widget, event->x, event->y);
	} else if (event->button == GDK_BUTTON_SECONDARY) {
		clear_surface();
		gtk_widget_queue_draw(widget);
	}

	return TRUE;
}

gboolean motion_notify_event_cb (GtkWidget *widget, GdkEventMotion *event, gpointer data) {
	if (surface == NULL) {
		return FALSE;
	}

	if (event->state & GDK_BUTTON1_MASK) {
		draw_brush(widget, event->x, event->y);
	}

	return TRUE;
}