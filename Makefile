INCLUDEFLAGS=-I/opt/vc/include -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/include/interface/vcos/pthreads -I..
LIBFLAGS=-L/opt/vc/lib -lEGL -lGLESv2 -lbcm_host -lpthread -ljpeg

test1: test1.c ../libshapes.o ../oglinit.o
	gcc -Wall $(INCLUDEFLAGS) -o test1 test1.c ../libshapes.o ../oglinit.o $(LIBFLAGS)
