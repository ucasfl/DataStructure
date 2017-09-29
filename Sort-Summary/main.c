#include "myheader.h"
int main( ) {
	Array List[7];
	int i, j;
	for(i = 0; i < MAXLEN; i ++){
		int data = rand() % 1000 + 1;
		for ( j = 0; j < 7; j++ )
		  List[j].record[i] = data;
	}
	for ( j = 0; j < 7; j++ )
	  List[j].length = MAXLEN;
	bubblesort(&List[0]);
	insertsort(&List[1]);
	mergesort(&List[2], 1, MAXLEN );
	quickSort(&List[3], 1, MAXLEN );
	radixSort(&List[4]);
	selectSort(&List[5]);
	shellSort(&List[6]);
	return 0;
}
