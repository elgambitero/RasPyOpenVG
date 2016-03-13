#include <Python.h>
#include "test1.h"

//This module is a hello world to C python binding
//Jaime Garcia Villena - elgambitero@gmail.com
//http://github.com/elgambitero

//This is licensed with GPLv2


static PyObject *
test1_rect(PyObject *self, PyObject *args)
{
	test1();
	return;
}
