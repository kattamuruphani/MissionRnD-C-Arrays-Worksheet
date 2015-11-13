/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<atlalloc.h>
void remove(int*,int);

void sort(int*, int, int);
void * removeArrayDuplicates(int *Arr, int len)
{
	if (len <= 0 || Arr == NULL){
		return NULL;
	}
	sort(Arr, 0, len - 1);
	remove(Arr, len);
	return Arr;
}




void sort(int *x, int first, int last){
	int pivot, j, temp, i;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (x[i] <= x[pivot] && i<last)
				i++;
			while (x[j]>x[pivot])
				j--;
			if (i<j){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}

		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		sort(x, first, j - 1);
		sort(x, j + 1, last);

	}
}


void remove(int *a, int len){
	int i, x, j = 0;
	int *binary;
	binary = (int*)malloc(sizeof(int)*(len));
	for (i = 0; i < len; i++){
		x = a[i];
		binary[i] = 1;
		while (x == a[i + 1]){
			i++;
			binary[i] = 0;
		}
	}
	for (i = 0, j = 0; i < len; i++){
		if (binary[i] == 1){
			a[j] = a[i];
			j++;
		}
	}

}
