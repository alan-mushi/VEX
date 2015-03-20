#include <stdio.h>
#include <stdlib.h>
//#include <vex_simd.h>

#define BUF_SIZE 128

/** 
 * Copy input file to output file
 **/
int main(int argc, char **argv) {
	FILE *inFile;
	FILE *outFile;
	char buffer[BUF_SIZE];
	
	if(argc < 3) {
		fprintf(stderr, "Usage: %s input output\n", argv[0]);
		exit(-1);
	}
	
	inFile = fopen(argv[1], "r");
	outFile = fopen(argv[2], "w");
	if(inFile == NULL || outFile == NULL) {
		fprintf(stderr, "Cannot open file!\n");
		exit(-2);
	}
	
	 do {
		fgets(buffer, BUF_SIZE, inFile);
		if(!feof(inFile)) {
			fprintf(outFile, "%s", buffer);
		}
	} while(!feof(inFile));
	
	fclose(inFile);
	fclose(outFile);
	
	return 0;
}
