#include "color_chooser.h"

#include <FL/Fl_Color_Chooser.H>

#include "_cgo_export.h"

void go_fltk_Color_Chooser_set_mode(Fl_Color_Chooser* Color_Chooser, int newMode) {
  Color_Chooser->mode(newMode);
}

int go_fltk_Color_Chooser_get_mode(Fl_Color_Chooser* Color_Chooser) {
  return Color_Chooser->mode();
}

Fl_Color_Chooser* go_fltk_new_Color_Chooser(int X, int Y, int W, int H, const char* title) {
  Fl_Color_Chooser* c = new Fl_Color_Chooser(X, Y, W, H, title);
  go_fltk_Color_Chooser_set_mode(c, 0);
  return c;
}

void go_fltk_Color_Chooser_destroy(Fl_Color_Chooser* Color_Chooser) {
  delete Color_Chooser;
}

void go_fltk_Color_Chooser_popup(Fl_Color_Chooser* Color_Chooser) {

  // Copy of popup() functions from fl_file_dir.cxx from Fltk source code.
  Color_Chooser->show();

  // deactivate Fl::grab(), because it is incompatible with modal windows
  Fl_Window* g = Fl::grab();
  if (g) Fl::grab(0);

  while (Color_Chooser->visible_r())
    Fl::wait();

  if (g) // regrab the previous popup menu, if there was one
    Fl::grab(g);
}