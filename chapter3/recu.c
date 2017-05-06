//3.25
#include<stdio.h>
#include<stdlib.h>

int Recu(int);
int NoRecu(int);

int main(){
	int n;
	scanf("%d",&n);
	int result1=Recu(n);
	int result2=NoRecu(n);
	printf("result1=%d\nresult2=%d\nRecu(%d)%cNoRecu(%d)\n",result1,result2,n,(result1==result2)?'=':(result1>result2)?'>':'<',n);
	return 0;
}

int Recu(int n){
	if(n==0)
	  return n+1;
	else
	  return Recu(n/2)*n;
}

int NoRecu(int n){
	int result=1;
	while(n!=0){
		result=result*n;
		n=n/2;
	}
	return result;
}
