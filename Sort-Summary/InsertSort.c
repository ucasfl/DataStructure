#include "myheader.h"
void insertsort(Array *List){
	int i, j;
	for ( i = 2; i < List->length + 1; i++ ) {
		for ( j = i - 1; j >= 1 && List->record[j] > List->record[i]; j-- ) {
			List->record[j + 1] = List->record[j];
		}
		List->record[j+1] = List->record[i];
	}
}
