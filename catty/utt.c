#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	char *input_path = "go";
	char *head_path = "~/Manual/";
	
	int count = strlen(head_path);
	int countp = strlen(input_path);
	
	char *abs_path = malloc(count + countp);
	
	int i = 0;
	for (i = 0; i < count; i++) {
		abs_path[i] = abspath[i];
	}
	
	for (i = 0;i < countp; i++) {
		abs_path[i+count] = path[i];
	}

	printf("%s\n", abs_path);
	free(abs_path);
}
