#include <cairo.h>

int main(int argc, char *argv[])
{
  cairo_surface_t *surface;
  cairo_t *cr;
  //Context
  surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,320,320);
  cr = cairo_create(surface);
  //Show Text
  cairo_set_source_rgb(cr,0,0,0);
  cairo_move_to(cr,10.0,50.0);
  cairo_show_text(cr,"hello, world");

  cairo_destroy(cr);
  cairo_surface_write_to_png(surface, "hello.png");
  cairo_surface_destroy(surface);
  return 0;
}
