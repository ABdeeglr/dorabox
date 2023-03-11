#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <direct.h>

char* get_path(char* path);
void printfile(char* filename);

void test(){
	char buffer[MAXPATH];
	getcwd(buffer, MAXPATH);
	printf("Current: %s\n", buffer);
}

int main(int argc, char* argv[]){
	if (argc == 1) {
		printf("Hello! Catty is a self-designed manual GUIDE.\nJust like a lite man.\n");
	return 2;
	}
	printf("-----------Test 1:Run!-----------\n");

	if (argc != 2) {
		printf("Can not find.\n");
		return -1;
	}
	// printf("-----------Test 2:Run!-----------\n");
	// printf("%s\n", argv[1]);

	// char* ins = argv[1];
	// printf("%s\n", ins);
	// char* abq = "-l";
	if (strcmp(argv[1],"-l") == 0) {
		// test(); 用于 -l 项目，但目前没有合适的函数

		return 0;
	}
	else {
		char *PATH = get_path(argv[1]);
		printfile(PATH);
		free(PATH);
		return 0;
	}
}


char* get_path(char* path){
	char *input_path = path;
	char *head_path = "/home/abdeeglr/Manual/";
	
	int count = strlen(head_path);
	int countp = strlen(input_path);
	
	char *abs_path = malloc(count + countp);
	
	int i = 0;
	for (i = 0; i < count; i++) {
		abs_path[i] = head_path[i];
	}
	
	for (i = 0;i < countp; i++) {
		abs_path[i+count] = input_path[i];
	}
	// printf("%s\n", abs_path);

	return abs_path;
}



