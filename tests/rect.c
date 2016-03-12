#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

static PyObject *rect_initDisplay(PyObject *self, PyObject *args){
  init(&width, &height);
  Py_RETURN_NONE;
}

static PyObject *rect_rect(PyObject *self, PyObject *args){
  Fill(255, 255, 255, 1);
	int i;
	for(i=0;i<3;i++){
		Start(width,height);
		Background(0,0,0);
		Fill(255,255,255,1);
		Rect(240,200,400,400);
		End();
		sleep(2);
		Background(0,0,0);
		End();
		sleep(1);
	}
  Py_RETURN_NONE;
}

static PyObject *rect_endDisplay(PyObject *self, PyObject *args){
  finish();
  Py_RETURN_NONE;
}

static PyMethodDef rect_methods[] = {
  {"initDisplay", (PyCFunction)rect_initDisplay, METH_NOARGS, NULL},
  {"rect", (PyCFunction)rect_rect, METH_NOARGS, NULL},
  {"endDisplay", (PyCFunction)rect_endDisplay, METH_NOARGS, NULL},
}
