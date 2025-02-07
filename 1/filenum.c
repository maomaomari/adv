#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int f_linenum(char *filename){
	FILE *file = fopen(filename, "r");
	char* buf = malloc(sizeof(char)*256);
	size_t size = 0;
	int line;
	while(getline(&buf, &size, file) != -1)
		{
			line++;
}
	fclose(file);
	return line;
}

int main(int argc, char** argv){
	assert(argv[1]);
	printf("%d\n", f_linenum(argv[1]));
	return 0;
}
