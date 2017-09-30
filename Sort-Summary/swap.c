#include "myheader.h"
void swap(Array *List, int m, int n){
	int t = List->record[m];
	List->record[m] = List->record[n];
	List->record[n] = t;
}
