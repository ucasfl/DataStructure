//1_19
#include<stdio.h> 
#include<limits.h>

long count(int);
int main(){
	int n;
	scanf("%d",&n); //input value n
	int array[n];
	long value;
	int i;
	for(i=0;i<n;i++){
		value=count(i);  //count value 
		if(value>INT_MAX/2){   //judge if bigger than INT_MAX
			printf("Too Big Value!\n");  //error
			return 0;
		}
		if(i==0)
		  array[i]=value;
		else
		  array[i]=value*2;
	}
	for(i=0;i<n;i++)
	  printf("array[%d]=%d\n",i,array[i]);  //output result
	return 0;
}
long count(int n){
	long value,jie,pow;
	int i;
	if(n==0)
	  return 1;//n==0ʱ£¬ֱ½ӷµ»أ1
	for(i=1,jie=pow=1;i<n;i++){
		jie*=i;                    //count n!
		pow*=2;                   //count 2^n
	}
	value=jie*pow*n;               //返回一半
	return value;
}
