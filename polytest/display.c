#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"


static int width, height;


static PyObject *display_init(PyObject *self, PyObject *args){ //do this properly
//	int width, height;
	init(&width, &height);
	Start(width,height);
  Py_RETURN_NONE;
}

static PyObject *display_expose(PyObject *self, PyObject *args){
	Start(width,height); //start composing the image
	Background(0,0,0); //background is black

	PyObject *contours; //this holds all the contours in the layer.
	int count; //this is the amount of contours.

	//get the contours tuple from arguments.
	if (!PyArg_ParseTuple(args,"i0",&count,&contours)){
		return NULL;
	}

	//now you have a tuple of contours.
	//Let's draw them all
	int i;//iterating variable
	for (i=0;i<=count;i++){
			PyObject *contour;
			//Get the proper contour
			contour = PyTuple_GetItem(contours,i);
			int color; //holds the color of the contour
			long csize; //holds the number of points
			PyObject *Xlist; //holds the x coordinates of the points
			PyObject *Ylist; //holds the y coordinates of the points
			double *xpoints; //C array that holds the x coordinates
			double *ypoints; //C array that holds the y coordinates

			//Extract size, color and coordinates of the contour.
			if(!PyArg_ParseTuple(contour,"ii00",&csize,&color,&Xlist,&Ylist)){
				return NULL;
			}

			//Turn the tuples into c arrays
			xpoints = (double *) malloc(sizeof(double)*csize);
			ypoints = (double *) malloc(sizeof(double)*csize);

			long j;//iterating variable
			for(j = 0;j<csize;j++){
				PyObject *xpoint;
				PyObject *ypoint;
				xpoint = PyList_GetItem(Xlist,j);
				ypoint = PyList_GetItem(Ylist,j);
				if (!PyFloat_Check(xpoint) || !PyFloat_Check(ypoint)) {
         		free(xpoints);
         		free(ypoints);
         		PyErr_SetString(PyExc_TypeError, "expected sequence of integers");
         	 return NULL;
      	}
			}
			//put the point into the array.
			xpoints[j] = PyFloat_AsDouble(xpoint);
			ypoints[j] = PyFloat_AsDouble(ypoint);
		}

		//construct the image
 		if(color == 1){
			Fill(255,255,255,1);
		}
		else{
			Fill(0,0,0,1);
		}
		Polygon((float*)xpoints,(float*)ypoints,csize);

		//dispose the memory for xpoints and ypoints maybe??
		free(xpoints);
		free(ypoints);
	}
	//All contours loaded

	End(); //End composing the image and show.
	Py_RETURN_NONE;
}

static PyObject *display_blank(PyObject *self, PyObject *args){
	Start(width,height);
	Background(0,0,0);
	End();
	Py_RETURN_NONE;
}

static PyObject *display_polyline(PyObject *self, PyObject *args) {

//	init(&width, &height);

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

//	finish();
	Py_RETURN_NONE;
}


static PyObject *display_finish(PyObject *self, PyObject *args){
  finish();
  Py_RETURN_NONE;
};

static PyMethodDef display_methods[] = {
  {"init", (PyCFunction)display_init, METH_NOARGS, NULL},
  {"polyline", (PyCFunction)display_polyline, METH_NOARGS, NULL},
  {"expose", (PyCFuntcion)display_expose ,METH_VARARGS, NULL},
  {"finish", (PyCFunction)display_finish, METH_NOARGS, NULL},
};

DL_EXPORT(void) initdisplay(void)
{
	Py_InitModule("display",display_methods);
}
