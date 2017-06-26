//10.41
#include<stdio.h>
#include<stdlib.h>
#define LEN 1000

void sort( int n[] );

int main( int argc, char **argv ) {
	int n[LEN];
	for ( int i = 0; i < LEN; i++ ) {
		n[i] = rand()%(10*LEN);
	}
	sort( n );
	printf( "Output sorted results:\n" );
	int j = 0;
	for ( int i = 0 ; i < LEN; i++ ) {
		j = (++j) % 10;
		if(j)
		  printf( "%d\t", n[i] );
		else
		  printf( "%d\n", n[i] );
	}
	printf( "\n" );
	return 0;
}

void sort( int n[] ){
	int hash[10000];
	int i, j, k;
	for ( i = 0; i < 10000; i++ ) {//initial the table
		hash[i] = 0;
	}
	for ( i = 0; i < 1000; i++ ) {//count the hash value and insert into hash[]
		for( j = n[i]; hash[j]; j = (j + 1) % 10000 )
		  ;
		hash[j] = n[i];
	}
	for ( i = 0, j = 0; i < 1000 && j < 10000; j ++ ){ //get the sorted array from hash table 
		if ( hash[j] ){
			for ( int x = hash[j], k = j; hash[k]; k = ( k + 1 ) % 10000 )
			  if ( hash[k] == x ){
				  n[i++] = x;
				  hash[k] = 0;
				  break;  //find record, break the inner loop
			  }
		}
	}
}
