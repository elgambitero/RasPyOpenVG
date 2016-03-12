#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

int main() {
	int width, height;
	init(&width, &height);

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
	finish();
	exit(0);
}

