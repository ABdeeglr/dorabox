/*
 * @file   : dora_support.c
 * Author  : abdeeglr <abdeeglr@icloud.com>
 * Init    : 2023.03.11
 * Usage   : This is a library for my tools.
 * Hitory  :
 * 		Latest		Init
 * 		2020.03.11	Init
 */


void printfile(char* filename){
	printf("Path:%s\n", filename);
	int ch;
	FILE* guide;
	guide = fopen(filename, "r");

	while ((ch = getc(guide)) != EOF){
		putchar(ch);
	}

	if (fclose(guide) != 0) printf("Error in closing file %s.\n", filename);
}
