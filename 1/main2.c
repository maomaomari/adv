/*
  --- Day 1: Historian Hysteria ---

The Chief Historian is always present for the big Christmas sleigh launch, but
nobody has seen him in months! Last anyone heard, he was visiting locations that
are historically significant to the North Pole; a group of Senior Historians has
asked you to accompany them as they check the places they think he was most
likely to visit.

As each location is checked, they will mark it on their list with a star. They
figure the Chief Historian must be in one of the first fifty places they'll
look, so in order to save Christmas, you need to help them get fifty stars on
their list before Santa takes off on December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day
in the Advent calendar; the second puzzle is unlocked when you complete the
first. Each puzzle grants one star. Good luck!

You haven't even left yet and the group of Elvish Senior Historians has already
hit a problem: their list of locations to check is currently empty. Eventually,
someone decides that the best place to check first would be the Chief
Historian's office.

Upon pouring into the office, everyone confirms that the Chief Historian is
indeed nowhere to be found. Instead, the Elves discover an assortment of notes
and lists of historically significant locations! This seems to be the planning
the Chief Historian was doing before he left. Perhaps these notes can be used to
determine which locations to search?

Throughout the Chief's office, the historically significant locations are listed
not by name but by a unique number called the location ID. To make sure they
don't miss anything, The Historians split into two groups, each searching the
office and trying to create their own complete list of location IDs.

There's just one problem: by holding the two lists up side by side (your puzzle
input), it quickly becomes clear that the lists aren't very similar. Maybe you
can help The Historians reconcile their lists?

For example:

3   4
4   3
2   5
1   3
3   9
3   3

Maybe the lists are only off by a small amount! To find out, pair up the numbers
and measure how far apart they are. Pair up the smallest number in the left list
with the smallest number in the right list, then the second-smallest left number
with the second-smallest right number, and so on.

Within each pair, figure out how far apart the two numbers are; you'll need to
add up all of those distances. For example, if you pair up a 3 from the left
list with a 7 from the right list, the distance apart is 4; if you pair up a 9
with a 3, the distance apart is 6.

In the example list above, the pairs and distances would be as follows:

    The smallest number in the left list is 1, and the smallest number in the
right list is 3. The distance between them is 2. The second-smallest number in
the left list is 2, and the second-smallest number in the right list is
another 3. The distance between them is 1. The third-smallest number in both
lists is 3, so the distance between them is 0. The next numbers to pair up are 3
and 4, a distance of 1. The fifth-smallest numbers in each list are 3 and 5, a
distance of 2. Finally, the largest number in the left list is 4, while the
largest number in the right list is 9; these are a distance 5 apart.

To find the total distance between the left list and the right list, add up the
distances between all of the pairs you found. In the example above, this is 2 +
1 + 0 + 1 + 2 + 5, a total distance of 11!

Your actual left and right lists contain many location IDs. What is the total
distance between your lists?

To play, please identify yourself via one of these services:
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
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void b_sort(int arr[], int n);
int f_linenum(char*);

int main(int argc, char **argv){
	assert(argv[1] != NULL);
	int linen = f_linenum(argv[1]);
	FILE *file = fopen(argv[1], "r");
	//	int lista_d[linen], lista_e[linen];
	int *lista_d, *lista_e;
	
	lista_d = (int*)malloc(sizeof(int)*linen);
	lista_e = (int*)malloc(sizeof(int)*linen);
	
	for(int i = 0; fscanf(file, "%d   %d", &lista_d[i], &lista_e[i]) == 2; i++);
	fclose(file);
	b_sort(lista_d, linen);
	b_sort(lista_e, linen);

	int64_t dift;
	printf("DIR\tESQ\tTOT\n");
	for(int i = 0; i < linen; i++){
		int dif = (lista_d[i] > lista_e[i]) ? lista_d[i] - lista_e[i] : lista_e[i] - lista_d[i];
		printf("%d\t%d\t%d\n", lista_d[i], lista_e[i], dif);
		dift += dif;
	}
	printf("\nTOTAL: %ld\nTOTAL LINES: %d\n", dift, linen);

	return 0;
}

void b_sort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int f_linenum(char *filename){
	FILE *file = fopen(filename, "r");
	char* buf = malloc(sizeof(char)*256);
	size_t size = 256;
	int line;
	while(fgets(buf, size, file) != NULL)
		{
			line++;
}
	fclose(file);
	return line;
}
