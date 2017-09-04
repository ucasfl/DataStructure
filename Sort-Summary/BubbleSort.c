#include "myheader.h"
void bubblesort(Array *List){
	int sorted = 0;
	int i = List->length; 
	while ( !sorted ) { //judge whether sorted
		sorted = 1;
		for ( int j =1; j < i; j++ ) { //zero location not use
			if(List->record[j + 1] < List->record[j]){ //exchange value 
				int t = List->record[j];
				List->record[j] = List->record[j + 1];
				List->record[j + 1] = t;
				sorted = 0; //set not sorted flag
			}
		}
		i--;
	}
}
