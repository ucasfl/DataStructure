#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<assert.h>
#define MAXLEN 1000
typedef struct {
	int record[MAXLEN + 1];
	int length;
}Array;
void bubblesort(Array *List);
void insertsort(Array *List);
void mergesort(Array *List, int low, int high);
void merge(Array *List, int low, int mid, int high);
void quickSort(Array *List, int low, int high);
void swap(Array *List, int m, int n);
void radixSort(Array *List);
void Sort(int temp[], Array *List);
void selectSort(Array *List);
void GetElem(Array *List, int i, int *index);
void shellSort(Array *List);
