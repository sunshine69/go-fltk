package fltk

/*
#include <stdlib.h>
#include "color_chooser.h"
*/
import "C"
import (
	"errors"
	"unsafe"
	"fmt"
)

type ColorChooser struct {
	cPtr                     *C.Fl_Color_Chooser
	R, G, B  				 *C.double
	callbackId               uintptr
}

var ErrColorChooserDestroyed = errors.New("color chooser is destroyed")

type ColorChooserType int

func NewColorChooser(X, Y, W, H int, title string) *ColorChooser {
	c := &ColorChooser{}
	titleC := C.CString(title)
	defer C.free(unsafe.Pointer(titleC))
	c.cPtr = C.go_fltk_new_Color_Chooser(C.int(X), C.int(Y), C.int(W), C.int(H), titleC)
	return c
}

func (c *ColorChooser) ptr() *C.Fl_Color_Chooser {
	if c.cPtr == nil {
		panic(ErrColorChooserDestroyed)
	}
	return c.cPtr
}
func (c *ColorChooser) Destroy() {
	fmt.Println("Destroy func in filechooser called")
	if c.callbackId > 0 {
		globalCallbackMap.unregister(c.callbackId)
	}
	C.go_fltk_Color_Chooser_destroy(c.ptr())
	c.cPtr = nil
}

func (c *ColorChooser) Popup() {
	C.go_fltk_Color_Chooser_popup((*C.Fl_Color_Chooser)(c.ptr()))
}