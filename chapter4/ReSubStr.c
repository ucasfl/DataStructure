#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define LENGTH 100
void GetLReSubStr(char s[]){ /*find the longest repeat substring*/
	int i,j;
	int location1, location2; /*record the location of string s and s2*/
	int k ;
	int maxlen = 0; /*record the length*/
	int len = strlen(s);
	for( i = 1; i < len; i++){ /*把s不断平移，然后进行匹配*/
		for (k = 0, j = 0; j < len -i; j++ ) {
			if(s[j] == s[j+i])
			  k++;
			else
			  k = 0;
			if ( k > maxlen ) {
				location1 = j - k + 1, location2 = location1 + i; maxlen = k;
			}
		} /*for*/
	}  /*for*/
	if ( maxlen > 0 ) {
		printf( "location1 = %d, location2 = %d, maxlen = %d\n",location1,location2,maxlen );
	}
	else {
		printf( "No repeat substring\n" ); //no repeat substring
	}
} //算法的时间复杂度为O(n^2),n为串的长度

void GetLReSubStr(char s[]); //函数声明

int main( int argc, char **argv ) {
	char s[LENGTH];
	scanf("%s",s);
	GetLReSubStr(s);
	return 0;
}
