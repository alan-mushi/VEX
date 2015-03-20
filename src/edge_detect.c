/*
 Copyright (C) 2006 Pedro Felzenszwalb

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <common.h>
//#include <math.h>

#define min(x,y) ( (x)>(y)?(y):(x))

#define W 2048
#define H 2048

#define BITSPERLONG 8

#define TOP2BITS(x) ((x & (3 << (BITSPERLONG-2))) >> (BITSPERLONG-2))

unsigned short isqrt(unsigned int x) {
	unsigned short a = 0L; /* accumulator */
	unsigned int r = 0L; /* remainder */
	unsigned int e = 0L; /* trial product */

	int i;

	for (i = 0; i < BITSPERLONG; i++) /* NOTE 1 */
	{
		r = (r << 2) + TOP2BITS(x);
		x <<= 2; /* NOTE 2 */
		a <<= 1;
		e = (a << 1) + 1;
		if (r >= e) {
			r -= e;
			a++;
		}
	}
	return a;
}

int Gx[MAX_WIDTH][MAX_HEIGHT];
int Gy[MAX_WIDTH][MAX_HEIGHT];
//#pragma prefetch(10)
unsigned char in[MAX_WIDTH][MAX_HEIGHT];
//#pragma prefetch(10)
unsigned char out[MAX_WIDTH][MAX_HEIGHT];

extern void deriche_fused(int width, int height);
extern void deriche_slow(int width, int height);

int main(int argc, char **argv) {

	int width, height;

	int t = 0;
	int mode = 0;

#ifdef VEX
	sim_ta_disable();
#endif
	fprintf(stderr, "usage: %s in.pgm out.pgm mode={float_slow,fixed_slow,fixed_fast}\n", argv[0]);

	if (argc < 3) {
		fprintf(stderr, "usage: %s in.pgm out.pgm mode", argv[0]);
		exit(1);
	}


	if (argc == 4) {
		if (strcmp(argv[3], "float_slow")==0) {
			mode = 1;
		} else if (strcmp(argv[3], "fixed_slow")==0) {
			mode = 2;
		} else if (strcmp(argv[3], "fixed_fast")==0) {
			mode = 3;
		}
	}

	if (mode == 0) {
		fprintf(stderr, "unknown operating mode %s\n", argv[3]);
		exit(1);
	} else {

	}


	// load input
	load_pgm(argv[1], &width, &height, in);
	fprintf(stdout,"loaded ...");

	#ifdef VEX
	sim_ta_enable();
#endif

	switch (mode) {
	case 1:
		deriche_float(width, height);
		break;
	case 2:
		deriche_slow(width, height);
		break;
	case 3:
		deriche_fused(width, height);
		break;
	}

#ifdef VEX
	sim_ta_finish();
#endif
	// save results
	save_pgm(argv[2], width, height, out);
	return 0;
}
