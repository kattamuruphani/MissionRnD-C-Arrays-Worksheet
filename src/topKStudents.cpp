/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
void sort1(struct student*, int,int);
void swap(struct student*, struct student*);

struct student ** topKStudents(student *students, int len, int K) {
	if (len <= 0 || K <= 0 || students == NULL){
		return NULL;
	}
	if (K >= len){
		K = len;
	}
	int i;
	struct student **temp;
	temp = (struct student**)malloc(sizeof(struct student*)*K);
	sort1(students, len, K);
	for (i = 0; i < K; i++){
		temp[i] = &students[i];
	}
	return temp;



}




void sort1(struct student *students, int len, int K){
	int j, i;


	for (i = 0; i < K; i++){
		for (j = i + 1; j < len; j++){
			if (students[i].score<students[j].score){
				swap(&students[i], &students[j]);
			}
		}
	}
}



void swap(struct student *a, struct student *b){
	struct student temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

