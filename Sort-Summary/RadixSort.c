#include "myheader.h"
//just to illustrate the theory of radix sort, 
//but not a good idea here to sort numbers
//suppose all numbers more then zero and less than or equal 1000
void radixSort(Array *List){
	int temp[List->length];
	int i ;
	for( i = 0; i < List->length; i ++ )
	  temp[i] = List->record[i + 1] % 10;
	Sort(temp, List);//sort by the unit
	for( i =0; i < List->length; i ++ )
	  temp[i] = (List->record[i + 1] % 100 ) / 10;
	Sort(temp, List);//sort by decade
	for( i = 0; i < List->length; i ++ )
	  temp[i] = List->record[i + 1] / 100;
	Sort(temp, List);//sort by huntreds
}
void Sort(int temp[], Array *List){
	int i, j ;
	for ( i = 0; i < List->length - 1; i++  ){
		for (j = 0; j < List->length - i - 1; j++)
		  if(temp[j + 1] < temp[j])
			swap(List, j + 1, j + 2);
	}

}
