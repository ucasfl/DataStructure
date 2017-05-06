#include<stdio.h>
int fibo(int, int);
int main(void)
{
  int k,m,f;
  printf("please enter two integers:");
  while(scanf("%d %d",&k,&m)==2)
  {
     f=fibo(k,m);
     printf("f(k,m) = %d\n",f);
     printf("please enter next two integers:");
  }
  return 0;
}
int fibo(int a,int b)
{
    int f;
    int p[b+1];
    if(b<(a-1))
        f=0;
    else if(b==(a-1))
        f=1;
    else
    {
        int i, j;
        for(i=0;i<(a-1);i++)
            p[i]=0;
              p[a-1]=p[a]=1;
                 for(j=a+1;j<=b;j++)
                    p[j]=2*p[j-1]-p[j-a-1];
        f=p[b];
    }
    return f;
}
      
    
