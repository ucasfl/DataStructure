/*4.10*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRSIZE 30
typedef char StringType;
void reverse(StringType	s[],int ,int);

int main( int argc, char **argv ) {
	StringType s[STRSIZE];
	scanf("%s",s); /*input string*/
	printf( "Before reverse:\n%s\n",s);
	reverse(s,0, strlen(s)-1);
	printf( "After reverse:\n%s\n",s );
	return 0;
}

void reverse(StringType s[],int m,int n){ /*recusive reverse string*/
	StringType t;
	if ( m<n&&(m+1)>=(n-1) ) {
		t = s[m], s[m] = s[n],s[n] = t; /*end of func*/
		return ;
	}
	else{
		t = s[m],s[m] = s[n],s[n] = t;
		reverse(s,m+1,n-1); /*new call*/
	}
}
