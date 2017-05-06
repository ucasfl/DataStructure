//1.20
#include<stdio.h>
long count(int [],int n,int x);   //count poly value
int main(){
	int n,x,i;
	printf("Enter value n:");
	scanf("%d",&n);   //input degree

	printf("Enter value x:");
	scanf("%d",&x);   //input x

	int cof[n+1];
	for(i=0;i<n+1;i++){
		printf("Enter a%d:",i);
		scanf("%d",&cof[i]);  //inoput coefficient a0-an
	}

	long pn;
	pn=count(cof,n,x); //count final value
	printf("Pn(%d)=%ld\n",x,pn);   //output result
	return 0;
}
long count(int cof[],int n,int x){
	int i;
	long p=0;
	for(i=n;i>0;i--)
	  p=(p+cof[i])*x;
	p+=cof[0];
	return p;
}

