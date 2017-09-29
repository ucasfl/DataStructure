#include "myheader.h"
void quickSort(Array *List, int low, int high){
	if ( low == high )
	  return ;
	List->record[0] = List->record[low];
	int lowtemp = low, hightemp = high;
	while ( lowtemp < hightemp ) {
		while( List->record[hightemp] >= List->record[0] )
		  hightemp--;
		swap(List, lowtemp, hightemp);
		while( List->record[lowtemp] <= List->record[0] )
		  lowtemp++;
		swap(List, lowtemp, hightemp);
	}
	quickSort(List, low, lowtemp -1);
	quickSort(List, lowtemp + 1, high);
}

void swap(Array *List, int m, int n){
	int t = List->record[m];
	List->record[m] = List->record[n];
	List->record[n] = t;
}
