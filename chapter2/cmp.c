//2.12
#include<stdio.h>
#include<stdlib.h>
//宏定义
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define EQUAL 0
#define SMALL -1
#define LARGE 1

#define LIST_INIT_SIZE 100    //线性表存储空间的初始分配量
#define LISTINCREMENT 10     //线性表存储空间的分配增量
typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType *elem;    //存储空间基址
	int length;        //当前长度
	int listsize;      //当前分配的存储容量
}SqList;

Status InitList_Sq(SqList *L){
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) exit(OVERFLOW);    //存储分配失败
	L->length=0;                    //空表长度为0
	L->listsize=LIST_INIT_SIZE;     //初始存储容量
	return OK;
}//InitList_Sq
//顺序表大小比较
Status Cmp_Sq(SqList *La,SqList *Lb){
    int i=0,j=0;
    while(La->elem[i++]==Lb->elem[j++]&&i<La->length&&j<Lb->length)//跨过相等的部分
    ;
    if(i==j&&i==La->length&&j==Lb->length&&La->elem[i-1]==Lb->elem[j-1])//La==Lb 
	  return EQUAL;
	else if((i<La->length&&j==Lb->length)||(i<=La->length&&j<=Lb->length&&La->elem[i-1]>Lb->elem[j-1]))//La>Lb
	  return LARGE;
	else         //La<Lb
	  return SMALL;
}

Status InitList_Sq(SqList *L);
Status Cmp_Sq(SqList *La,SqList *Lb);


int main(){
	SqList *L,*M,*N,*O,La,Lb,Lc,Ld;
	L=&La,M=&Lb,N=&Lc,O=&Ld;
	//初始化
	InitList_Sq(L);
	InitList_Sq(M);
	InitList_Sq(N);
	InitList_Sq(O);
	//赋值
	int i;
	for(i=0;i<20;i++){
		L->elem[i]=M->elem[i]=i;
		L->length++;
		M->length++;
	}
	for(i=0;i<25;i++){
		N->elem[i]=i;
		N->length++;
	}
	for(i=0;i<19;i++)
	  O->elem[i]=i,O->length++;
	O->elem[i]=10;
	O->length++;
	//打印
	printf("La:");
	for(i=0;i<20;i++)
	  printf("%d\t",L->elem[i]);
	printf("\nLb:");
	for(i=0;i<20;i++)
	  printf("%d\t",M->elem[i]);
	printf("\nLc:");
	for(i=0;i<25;i++)
	  printf("%d\t",N->elem[i]);
	printf("\nLd:");
	for(i=0;i<20;i++)
	  printf("%d\t",O->elem[i]);
	printf("\n");

	//比较
	int v1=Cmp_Sq(L,M);
	int v2=Cmp_Sq(L,N);
	int v3=Cmp_Sq(L,O);
	printf("La%cLb\n",(v1==0)?'=':(v1==-1)?'<':'>');
	printf("La%cLc\n",(v2==0)?'=':(v2==-1)?'<':'>');
	printf("La%cLd\n",(v3==0)?'=':(v3==-1)?'<':'>');
	return 0;
}
