/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

int* sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i, first, last, mid;
	if (len < 0 || Arr == NULL)
		return NULL;
	else if (len == 0){
		Arr = (int*)realloc(Arr, (len + 1)*sizeof(int));
		Arr[0] = num;
	}
	else{
		Arr = (int*)realloc(Arr, (len + 1)*sizeof(int));
		if (Arr[0] > num){
			for (i = 1; i <= len; i++)
			{
				Arr[i + 1] = Arr[i];
			}
			Arr[0] = num;
		}
		else if (Arr[len - 1] < num){
			Arr[len] = num;
		}
		else{
			first = 0;
			last = len - 1;

			while (first < last){
				mid = (first + last) / 2;
				if (Arr[mid]<num&&Arr[mid + 1]>num){
					break;
				}
				if (Arr[mid] > num){
					last = mid;
					continue;
				}
				else if (Arr[mid + 1] < num){
					first = mid;
					continue;
				}
			}
			for (i = len - 1; i >= mid + 1; i--){
				Arr[i + 1] = Arr[i];
			}
			Arr[mid + 1] = num;

		}

	}
	return Arr;
}