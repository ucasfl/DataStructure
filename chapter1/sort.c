//1.16
#include<stdio.h>
void sort(int [],int);
int main(void)
{
	int array[3],i;
	for(i=0;i<3;i++){
		printf("Please enter a number:");
		scanf("%d",&array[i]);  //input data
	}
	sort(array,3);  //sort data
	for(i=2;i>=0;i--)
	  printf("%d\t",array[i]); //output data
	printf("\n");
	return 0;
}
void sort (int array[],int n){
	int i,j;
	int t;
	for(i=0;i<n-1;i++)
	  for(j=0;j<n-i-1;j++)
		if(array[j]>array[j+1])
		  t=array[j],array[j]=array[j+1],array[j+1]=t;//bubble sort
}

