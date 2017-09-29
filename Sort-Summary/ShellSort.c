#include "myheader.h"
void shellSort(Array *List){
	int i, j,step = List->length / 2;
	while (step > 0){
		for ( i = 1 + step; i <= List->length; i += step )
		  for( j = i; j >=1 && List->record[j] < List->record[j - step]; j -= step ){
			  swap(List, j, j - step);
		  }
	}
	step /= 2;
}
