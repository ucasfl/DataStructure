#include "myheader.h"
void selectSort(Array *List){
	int i, index;
	for ( i = 1; i <= List->length; i ++ ){
		GetElem(List, i, &index);
		if (i != index)
		  swap(List, i, index);
	}
}
void GetElem(Array *List, int i, int *index){
	int j, min = List->record[i];
	*index = i;
	for ( j = i + 1; j <= List->length; j++ )
	  if (List->record[j] < min){
		  min = List->record[j];
		  *index = j;
	  }
}
