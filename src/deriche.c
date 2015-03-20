#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <common.h>

/* Main computational kernel. The whole function will be timed,
 including the call and return. */
/* Original code provided by Gael Deest */

extern unsigned char in[MAX_WIDTH][MAX_HEIGHT];
extern unsigned char out[MAX_WIDTH][MAX_HEIGHT];

float y1[MAX_WIDTH][MAX_HEIGHT];
float y2[MAX_WIDTH][MAX_HEIGHT];
float t[MAX_WIDTH][MAX_HEIGHT];


void deriche_float(int width, int height) {
	int i, j;

	float xm1, tm1, ym1, ym2;
	float xp1, xp2;
	float tp1, tp2;
	float yp1, yp2;
	float k;
	float a1, a2, a3, a4, a5, a6, a7, a8;
	float b1, b2, c1, c2;

	k = a1 = a5 = ( (-0.188682));
	a2 = a6 = ( (0.110209));
	a3 = a7 = ( (-0.183682));
	a4 = a8 = ( (0.114441));
	b1 = ( (0.840896));
	b2 = ( (-0.606531));
	c1 = c2 = (int) (1);

L1:
	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0;
		for (j = 0; j < height; j++) {
			y1[i][j] = (a1 * in[i][j] + a2 * xm1 + b1 * ym1 + b2 * ym2) ;
			xm1 = in[i][j];
			ym2 = ym1;
			ym1 = y1[i][j];
		}
	}

L2:
	for (i = 0; i < width; i++) {
		yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			y2[i][j] = (a3 * xp1 + a1 * xp2 + b1 * yp1 + b2 * yp2) ;
			xp2 = xp1;
			xp1 = in[i][j];
			yp2 = yp1;
			yp1 = y2[i][j];
		}
	}

L3:
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			t[i][j] = (c1 * (y1[i][j] + y2[i][j])) ;
L4:
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0;
		for (i = 0; i < width; i++) {
			y1[i][j] = (a5 * t[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) ;
			tm1 = t[i][j];
			ym2 = ym1;
			ym1 = y1[i][j];
		}
	}
L5:
	for (j = 0; j < height; j++) {
		tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			y2[i][j] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) ;
			tp2 = tp1;
			tp1 = t[i][j];
			yp2 = yp1;
			yp1 = y2[i][j];
		}
	}
L6:
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			out[i][j] = (c2 * (y1[i][j] + y2[i][j])) ;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}

}

/*  versions virgule fixe */


int qy1[MAX_WIDTH][MAX_HEIGHT];
int qy2[MAX_WIDTH][MAX_HEIGHT];
int qt[MAX_WIDTH][MAX_HEIGHT];

void deriche_fused(int width, int height) {
	int i, j;

	int xm1, tm1, ym1, ym2;
	int xp1, xp2;
	int tp1, tp2;
	int yp1, yp2;
	int k;
	int a1, a2, a3, a4, a5, a6, a7, a8;
	int b1, b2, c1, c2;

	k = a1 = a5 = (int) (256 * (-0.188682));
	a2 = a6 = (int) (256 * (0.110209));
	a3 = a7 = (int) (256 * (-0.183682));
	a4 = a8 = (int) (256 * (0.114441));
	b1 = (int) (256 * (0.840896));
	b2 = (int) (256 * (-0.606531));
	c1 = c2 = (int) (256);

	//...
}

void deriche_slow(int width, int height) {
	int i, j;

	int xm1, tm1, ym1, ym2;
	int xp1, xp2;
	int tp1, tp2;
	int yp1, yp2;
	int k;
	int a1, a2, a3, a4, a5, a6, a7, a8;
	int b1, b2, c1, c2;

	k = a1 = a5 = (int) (256 * (-0.188682));
	a2 = a6 = (int) (256 * (0.110209));
	a3 = a7 = (int) (256 * (-0.183682));
	a4 = a8 = (int) (256 * (0.114441));
	b1 = (int) (256 * (0.840896));
	b2 = (int) (256 * (-0.606531));
	c1 = c2 = (int) (256);

L1:
	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0;
		for (j = 0; j < height; j++) {
			qy1[i][j] = (a1 * (in[i][j] << 8) + a2 * xm1 + b1 * ym1 + b2 * ym2) >> 8;
			xm1 = in[i][j] << 8;
			ym2 = ym1;
			ym1 = qy1[i][j];
		}
	}

L2:
	for (i = 0; i < width; i++) {
		yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			qy2[i][j] = (a3 * xp1 + a1 * xp2 + b1 * yp1 + b2 * yp2) >> 8;
			xp2 = xp1;
			xp1 = in[i][j] << 8;
			yp2 = yp1;
			yp1 = qy2[i][j];
		}
	}

L3:
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			qt[i][j] = (c1 * (qy1[i][j] + qy2[i][j])) >> 8;
L4:
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0;
		for (i = 0; i < width; i++) {
			qy1[i][j] = (a5 * qt[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) >> 8;
			tm1 = qt[i][j];
			ym2 = ym1;
			ym1 = qy1[i][j];
		}
	}
L5:
	for (j = 0; j < height; j++) {
		tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			qy2[i][j] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) >> 8;
			tp2 = tp1;
			tp1 = qt[i][j];
			yp2 = yp1;
			yp1 = qy2[i][j];
		}
	}
L6:
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			out[i][j] = (c2 * (qy1[i][j] + qy2[i][j])) >> 16;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}
}
