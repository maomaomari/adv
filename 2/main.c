/*
  --- Day 2: Red-Nosed Reports ---

Fortunately, the first location The Historians want to search isn't a long walk from the Chief Historian's office.

While the Red-Nosed Reindeer nuclear fusion/fission plant appears to contain no sign of the Chief Historian, the engineers there run up to you as soon as they see you. Apparently, they still talk about the time Rudolph was saved through molecular synthesis from a single electron.

They're quick to add that - since you're already here - they'd really appreciate your help analyzing some unusual data from the Red-Nosed reactor. You turn to check if The Historians are waiting for you, but they seem to have already divided into groups that are currently searching every corner of the facility. You offer to help with the unusual data.

The unusual data (your puzzle input) consists of many reports, one report per line. Each report is a list of numbers called levels that are separated by spaces. For example:

7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9

This example data contains six reports each containing five levels.

The engineers are trying to figure out which reports are safe. The Red-Nosed reactor safety systems can only tolerate levels that are either gradually increasing or gradually decreasing. So, a report only counts as safe if both of the following are true:

    The levels are either all increasing or all decreasing.
    Any two adjacent levels differ by at least one and at most three.

In the example above, the reports can be found safe or unsafe by checking those rules:

    7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2.
    1 2 7 8 9: Unsafe because 2 7 is an increase of 5.
    9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.
    1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing.
    8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease.
    1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3.

So, in this example, 2 reports are safe.

Analyze the unusual data from the engineers. How many reports are safe?
*/
/*
  Copyright 2025 MARIA CLARA SKIBINSKI

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line_s{
	int* array;
	size_t arr_size;
}line_t;

int f_linenum(char*);
size_t ret_digitnum(char *);
void fetch_to_arr(int *array, char *string, size_t arr_size);

int main(int argc, char** argv){
	assert(argv[1] != NULL);
	int linenum = f_linenum(argv[1]);
	FILE *file = fopen(argv[1], "r");

	int** report = (int**)malloc(sizeof(int*)*linenum);
	char buff[512];
	for(int i = 0; i < linenum; i++ ){
		size_t arrsize = ret_digitnum(fgets(buff,512,file));
		report[i] = (int*) malloc(sizeof(int) * arrsize);
		fetch_to_arr(report[i], buff, arrsize);
	}
	for(int i = 0; i < linenum; i++)
		printf("arr: %d\n", report[i][0]);
	return 0;
}

int f_linenum(char *filename){
	FILE *file = fopen(filename, "r");
	char buf[256];
	int llen = 256;
	int linenum = 0;
	while(fgets(buf, llen, file) != NULL)
		linenum++;
	fclose(file);
	return linenum;
}
size_t ret_digitnum(char* string){
	size_t num = 0;
	for(int i = 0; string[i] != '\0'; i++){
		if(isdigit(string[i])){
			num++;
			while(isdigit(string[i]))
				i++;
		}
	}
		
	return num;
}
/*
  fetches ints from string to an array of size 'size
 */
void fetch_to_arr(int* array, char* string, size_t size){
	assert(size);
	for(int i = 0; i < size; i++){
		char buff[64];
		for(int j = 0; isdigit(string[j]); j++)
			buff[j] = string[j];
		array[i] = atoi(buff);
	}
}
