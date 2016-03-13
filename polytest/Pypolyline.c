#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

static PyObject *display_init(PyObject *self, PyObject *args){ //do this properly
	int width, height;
	init(&width, &height);
  Py_RETURN_NONE;
}


static PyObject *display_polyline(PyObject *self, PyObject *args) {
	//you want to parse this.
	float xpoints[10] = {100.0,200.0,300.0,200.0,400.0,100.0,150.0,20.0,600.0,400.0};
	float ypoints[10] = {500.0,300.0,350.0,600.0,550.0,450.0,700.0,240.0,400.0,300.0};


	Fill(255, 255, 255, 1);
	int i;
	for(i=0;i<3;i++){
		Start(width,height);
		Background(0,0,0);
		Fill(255,255,255,1);
		Polygon(xpoints,ypoints,10);
		End();
		sleep(2);
		Background(0,0,0);
		End();
		sleep(1);
	}
}


static PyObject *display_finish(PyObject *self, PyObject *args){
  finish();
  Py_RETURN_NONE;
};


static PyMethodDef display_methods[] = {
  {"initDisplay", (PyCFunction)display_init, METH_NOARGS, NULL},
  {"polyline", (PyCFunction)display_polyline, METH_NOARGS, NULL},
  {"endDisplay", (PyCFunction)display_finish, METH_NOARGS, NULL},
};

DL_EXPORT(void) initrect(void)
{
	Py_InitModule("display",display_methods);
}
