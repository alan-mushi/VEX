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
#include <math.h>
#include <common.h>



void** mat_malloc(int width, int height, int size) {
	unsigned char** line = (unsigned char**) malloc(width*sizeof(unsigned char *));
	{

		int i;

		for (i = 0; i < width; i++) {

			line[i] = (unsigned char*) malloc(height * size);

		}

	}

	return line;

}







