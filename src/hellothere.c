#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FRAMEHEIGHT 50 // text line height
#define FRAMEWIDTH 200 // text width
#define FRAMENUM 10
#define MAXFILEPATHLEN 50
#define FRAMET 210 //time between each frame - milleseconds

char * loadframe(int currentframe, int height, int width);

int main() {
	int i;
	
	for (i = 0; i < FRAMENUM; ++i) {
		int status = system("clear");
		printf("%s\n", loadframe(i, FRAMEHEIGHT, FRAMEWIDTH));
		usleep(FRAMET * 1000);
	}

	int status = system("clear");	
	return 0;
}

char * loadframe(int nframe, int height, int width) {
	char *frame = malloc (sizeof (char) * (height * width));
	FILE *fp;
	int c, i, charcount;

	charcount, i = 0;
	char filepath[] = "../assets/frame0.txt";
	
	for (i = 0; filepath[i] != '.'|| i < MAXFILEPATHLEN; ++i )
		if (filepath[i] == '0') {
			filepath[i] = ('0'+nframe);
			break;
		}		
	fp = fopen(filepath, "r");

	if (fp == NULL) {
		printf("%s\n", filepath);
		printf("Error: file does not exist\n");
		exit(0);
	}
	else {
		char c;
		int charcount = 0;
	
		while (((c = fgetc(fp)) != EOF ) && charcount < (FRAMEHEIGHT * FRAMEWIDTH)) {
			frame[charcount] = c;
			charcount++;				
		}
	}
	fclose(fp);
	return frame;
}
