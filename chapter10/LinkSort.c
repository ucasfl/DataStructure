//10.25
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 100

typedef int RcdType;

typedef struct{
	RcdType rc;
	int next;
}SLNode;

typedef struct{
	SLNode r[SIZE];
	int length;
}SLinkListType;

void SL_insertSort(SLinkListType *L);

int main( int argc, char **argv ) {
	SLinkListType L;
	printf( "Input length: " ); //input the linklist's length
	scanf("%d", &(L.length));
	printf( "Input record: " ); //input record
	for ( int i = 1; i <= L.length; i++ ) {
		scanf("%d", &(L.r[i].rc));
		L.r[i].next = 0;
	}
	SL_insertSort(&L); //sort the linklist
	for ( int i = 1; i <= L.length; i++ ) {  //output sorted result
		printf( "%d\n", L.r[i].rc );
	}
	return 0;
}

void SL_insertSort(SLinkListType *L){
	L->r[0].rc = INT_MAX; //set 0 record as the max reecord
	L->r[0].next = 1;
	L->r[1].next = 0; //initial the sort list
	int p, q, x;

	for ( int i = 2; i <= L->length; i++ ) { //insert everyone record
		p = 0;
		x = L->r[i].rc;
		while ( L->r[L->r[p].next].rc < x && L->r[p].next ) { //find the insert location
			p = L->r[p].next;
		}//while
		q = L->r[p].next; //insert record
		L->r[p].next = i;
		L->r[i].next = q;
	}//for

	p = L->r[0].next;
	for ( int i =1; i < L->length; i++ ) { //resort the location of the record
		while (p < i)
		  p = L->r[p].next;
		q = L->r[p].next;
		if(p != i){//exchange record 
			int rc_temp, next_temp;
			rc_temp = L->r[i].rc;
			L->r[i].rc = L->r[p].rc;
			L->r[p].rc = rc_temp;
			L->r[p].next = L->r[i].next;
			L->r[i].next = p;
		} //if
		p = q;
	}//for
}


