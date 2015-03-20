#include <stdio.h>
#include <vex_simd.h>


/** if the DEBUG mode is activated in libvexsimd, 
 * the result of each SIMD instruction will be dumped to stdout 
 **/
int main(int argc, char **argv) {
	v2x16 s1,s2, r;
	_UI16 s1e1, s1e0, s2e1, s2e0;
	v4x8 c1,c2;
	_UI8 c1e3, c1e2, c1e1, c1e0, c2e3, c2e2, c2e1, c2e0;
	int i;
	
	short A[10] = {0,1,2,3,4,5,6,7,8,9};
	char  B[12] = {0};

	ST_2x16(A+1, PACK_2x16(10, 20));
		
	for(i=0; i<5; i++) {
		ST_2x16(A+2*i, PACK_2x16(i, 10*i));
	}

	for(i=0; i<5; i++) {
		s1 = LD_2x16(A+2*i);
		printf("s1=%d, %d\n", EXT_16(s1,1), EXT_16(s1,0));
	}
/*

	for(i=0; i<7; i++) {
		c1 = LD_4x8(B+i);
		 printf("c1=%d, %d, %d, %d\n", EXT_8(c1,3), EXT_8(c1,2), EXT_8(c1,1), EXT_8(c1,0)); 
	}
*/
	s1 = PACK_2x16(5, 65530);
	s2 = PACK_2x16(3, 7);
	printf("s1=%d, %d\n", EXT_16(s1,1), EXT_16(s1,0));
	printf("s2=%d, %d\n", EXT_16(s2,1), EXT_16(s2,0));

	s1e1 = EXT_16(s1,1);
	s1e0 = EXT_16(s1,0);
	s2e1 = EXT_16(s2,1);
	s2e0 = EXT_16(s2,0);
	
	r = ADD_2x16(s1, s2);
	printf("r=%d, %d\n", EXT_16(r,1), EXT_16(r,0));
	r = SUB_2x16(s1, s2);
	r = MUL_2x16(s1, s2);
	r = DIV_2x16(s1, s2);
	r = SHR_2x16(s1, s2);
	r = SHL_2x16(s1, s2);

	r = ADDI_2x16(s1, 1);
	r = SUBI_2x16(s1, 2);
	r = MULI_2x16(s1, 3);
	r = DIVI_2x16(s1, 4);
	r = SHRI_2x16(s1, 1);
	r = SHLI_2x16(s1, 3);

	r = SFL2_2x16(3,2, s1, s2);
	r = SFL2_2x16(3,1, s1, s2);
	r = SFL2_2x16(3,0, s1, s2);
	r = SFL2_2x16(2,1, s1, s2);
	r = SFL2_2x16(2,0, s1, s2);
	r = SFL2_2x16(1,0, s1, s2);


	c1 = PACK_4x8(50, 128, 90, 250);
	c2 = PACK_4x8(5, 2, 7, 4);
	printf("c1=%d, %d, %d, %d\n", EXT_8(c1,3), EXT_8(c1,2), EXT_8(c1,1), EXT_8(c1,0)); 
	printf("c2=%d, %d, %d, %d\n", EXT_8(c2,3), EXT_8(c2,2), EXT_8(c2,1), EXT_8(c2,0));
	
	c1e3 = EXT_8(c1,3);
	c1e2 = EXT_8(c1,2);
	c1e1 = EXT_8(c1,1);
	c1e0 = EXT_8(c1,0);
	c2e3 = EXT_8(c2,3);
	c2e2 = EXT_8(c2,2);
	c2e1 = EXT_8(c2,1);
	c2e0 = EXT_8(c2,0);
	
	r = ADD_4x8(c1, c2);
	r = SUB_4x8(c1, c2);
	r = MUL_4x8(c1, c2);
	r = DIV_4x8(c1, c2);
	r = SHR_4x8(c1, c2);
	r = SHL_4x8(c1, c2);
	
	r = ADDI_4x8(c1, 15);
	r = SUBI_4x8(c1, 2); 
	r = MULI_4x8(c1, 3); 
	r = DIVI_4x8(c1, 4); 
	r = SHRI_4x8(c1, 2); 
	r = SHLI_4x8(c1, 3); 

	r = SFL2_4x8(7, 6, 5, 4, c1, c2);
	r = SFL2_4x8(3, 2, 1, 0, c1, c2);
	r = SFL2_4x8(7, 6, 3, 2, c1, c2);
	r = SFL2_4x8(5, 4, 1, 0, c1, c2);
	r = SFL2_4x8(0, 1, 2, 3, c1, c2);
	r = SFL2_4x8(4, 5, 6, 7, c1, c2);

	return 0;
}
