INCLUDEFLAGS=-I/opt/vc/include -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/include/interface/vcos/pthreads
LIBFLAGS=-L/opt/vc/lib -lEGL -lGLESv2 -lbcm_host -lpthread -ljpeg

test1: test1.c 
	gcc -Wall $(INCLUDEFLAGS) test1.c -o test1 -lshapes
