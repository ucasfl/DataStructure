//10.32
#include<stdio.h>
#include<stdlib.h>

typedef enum{RED, WHITE, BLUE}color;

void sort_flag(int flag[], int length);//sort flag

int main( int argc, char **argv ) {
	int length;
	printf( "Input length of flag: " );
	scanf("%d", &length);
	int flag[length];
	printf( "Input color: 0 = RED, 1= WHITE, 2 = BLUE:\n" );
	for ( int i = 0; i < length; i++ ) {//input flag
		scanf("%d", &flag[i]);
	}
	sort_flag(flag, length);
	printf( "Output sorted results:\n" );//output the sorted result
	for ( int i = 0; i < length; i++ ) {
		printf( "%d\n", flag[i] );
	}
	return 0;
}

void sort_flag( int flag[], int length ){
	int i = 0, j = 0, t;
	while ( j < length ) {
		switch (flag[j]){
			case RED://exchange RED to the first part
				t = flag[i];
				flag[i] = flag[j];
				flag[j] = t;
				i ++, j++;
				break;
			case WHITE://white not need change
				j ++;
				break;
			case BLUE://exchange BLUE to the last part
				t = flag[j];
				flag[j] = flag[length-1];
				flag[length-1] = t;
				length --;
		}
	}
}
