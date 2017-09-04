#include "myheader.h"
void mergesort(Array *List, int low, int high){
	if(high - low < 2 ){ //the recusion terminated
		if (List->record[high] >= List->record[low])
		  return;
		else{
			int t = List->record[high];
			List->record[high] = List->record[low];
			List->record[low] = t;
			return;
		}
	}
	else{//recursive merge the array
		int mid = (low + high)/2;
		mergesort(List, low, mid);
		mergesort(List, mid + 1, high);
		merge(List, low, mid, high);//merge two sorted array to one sorted array
	}
}
void merge(Array *List, int low, int mid, int high){
	int temp[MAXLEN + 1];
	int i, j, k;
	for ( int i = low; i <= high; i ++ )//merge array
	  temp[i] = List->record[i];
	for ( i = low, j = mid + 1, k = low; i <= mid && j <= high; ){
		if(temp[i] < temp[j])
		  List->record[k++] = temp[i++];
		else
		  List->record[k++] = temp[j++];
	}
	//merge the left part
	if (i > mid){
		while( j<= high )
		  List->record[k++] = temp[j++];
	}
	else{
		while( i <= mid )
		  List->record[k++] = temp[i++];
	}
}
