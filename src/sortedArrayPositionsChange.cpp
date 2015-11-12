/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, first = 0, last = 0, temp;
	int x = 1;
	if (len <= 0 || Arr == NULL){
		return NULL;
	}

	for (i = 0; i < len - 2; i++){
		if (Arr[i] > Arr[i + 1]){
			x = 0;
			first = i;
			break;
		}
	}

	for (i = len - 1; i > 0; i--){
		if (Arr[i] < Arr[i - 1]){
			last = i;
			x = 0;
			break;
		}
	}
	if (x == 0){
		temp = Arr[first];
		Arr[first] = Arr[last];
		Arr[last] = temp;
	}
	return Arr;
}