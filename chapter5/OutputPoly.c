//5.20
#include<stdio.h>
void OutputPoly(int array[][4][4]){
	for(int i = 9; i >= 0; i --){
		for(int i1 = 0; i1 <= 3; i1++){
			for(int i2 = 0; i2 <= 3; i2++){
				for(int i3 = 0; i3 <= 3; i3++){
					if(i1 + i2 + i3 == i){
						if(array[i1][i2][i3] != 0){
							if(i1 != 0 && i2 != 0 && i3 != 0)
							  printf( "%dx1E%dx2E%dx3E%d + ",array[i1][i2][i3], i1, i2, i3 );
							else if(i1 == 0 && i2 != 0 && i3 != 0)
							  printf( "%dx2E%dx3E%d + ",array[i1][i2][i3], i2, i3 );
							else if(i1 != 0 && i2 == 0 &&i3 != 0)
							  printf( "%dx1E%dx3E%d + ",array[i1][i2][i3],i1,i3 );
							else if ( i1 != 0 && i2 != 0 && i3 == 0 ) 
							  printf( "%dx1E%dx2E%d + ",array[i1][i2][i3],i1, i2 );
							else if(i1 == 0 && i2 == 0 && i3 != 0)
							  printf( "%dx3E%d + ",array[i1][i2][i3],i3 );
							else if(i1 == 0 && i2 != 0 && i3 == 0)
							  printf( "%dx2E%d + ",array[i1][i2][i3],i2 );
							else if(i1 != 0 && i2 == 0 && i3 ==0)
							  printf( "%dx1E%d + ",array[i1][i2][i3],i1 );
							else
							  printf( "%d\n",array[i1][i2][i3] );
						}
					}
				}
			}
		}
	}
}

int main( int argc, char **argv ) {
	int num[4][4][4];
	for(int i = 0; i < 4; i++)
	  for(int j = 0; j < 4; j++)
		for(int k =0; k < 4; k ++)
		  scanf("%d", &num[i][j][k]);
	OutputPoly(num);
	return 0;
}
