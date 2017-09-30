#include "myheader.h"
void quickSort(Array *List, int low, int high){
	if ( !(low < high - 1)){
		if( low == high - 1 && List->record[low] > List->record[high] )
		  swap(List, low, high);
		return ;
	}	List->record[0] = List->record[low];
	int lowtemp = low, hightemp = high;
	while ( lowtemp < hightemp ) {
		while( lowtemp < hightemp && List->record[hightemp] >= List->record[0] )
		  hightemp--;
		swap(List, lowtemp, hightemp);
		while( lowtemp < hightemp &&  List->record[lowtemp] <= List->record[0] )
		  lowtemp++;
		swap(List, lowtemp, hightemp);
	}
	quickSort(List, low, lowtemp -1);
	quickSort(List, lowtemp + 1, high);
}

