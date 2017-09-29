#include "myheader.h"
void insertsort(Array *List){
	int i, j;
	for( i = 2; i <= List->length; i++ )
	  for( j = i; j >=1 && List->record[j] < List->record[j - 1]; j-- ){
		  swap(List, j + 1, j);
	  }
}
