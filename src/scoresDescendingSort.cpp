/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
void sort(struct student*, int, int);

void * scoresDescendingSort(struct student *students, int len) {
	if (len <= 0 || students == NULL)
		return NULL;

	sort(students, 0, len - 1);
	return students;
}


void sort(struct student * x,int first, int last){
	int pivot, j, temp, i;
	
	

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (x[i].score >= x[pivot].score && i<last)
				i++;
			while (x[j].score<x[pivot].score)
				j--;
			if (i<j){
				temp = x[i].score;
				x[i].score = x[j].score;
				x[j].score = temp;
			}
		}

		temp = x[pivot].score;
		x[pivot].score = x[j].score;
		x[j].score = temp;
		sort(x, first, j - 1);
		sort(x, j + 1, last);

	}
}

