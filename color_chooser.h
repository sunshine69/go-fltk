#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct Fl_Color_Chooser Fl_Color_Chooser;

  extern Fl_Color_Chooser *go_fltk_new_Color_Chooser(int X, int Y, int W, int H, const char* title);

  extern void go_fltk_Color_Chooser_destroy(Fl_Color_Chooser* Color_Chooser);
  extern void go_fltk_Color_Chooser_set_callback(Fl_Color_Chooser* Color_Chooser, uintptr_t id);
  extern void go_fltk_Color_Chooser_popup(Fl_Color_Chooser* Color_Chooser);

#ifdef __cplusplus
}
#endif
