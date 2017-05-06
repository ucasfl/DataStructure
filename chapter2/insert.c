//2.11
#include<stdio.h>
#include<stdlib.h>
//宏定义
#define OK 1
#define ERROR 0
#define OVERFLOW -1

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

Status Insert_Sq(SqList *L,ElemType e){
	if(L->length >=L->listsize){ //当前存储空间已满，增加分配
		ElemType *newbase;
		newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);     //存储分配失败
		L->elem=newbase;                 //新基址
		L->listsize+=LISTINCREMENT;       //增加存储容量
	}	int i;
		if(L->elem[0]>=e)
		  i=0;                              //插在第一个元素前
		else if(L->elem[L->length-1]<=e)
		  i=L->length;                      //插在最后一个元素后
		else{                          //插在中间
			for(i=0;i<L->length-1;i++){
				if(e>=L->elem[i]&&e<=L->elem[i+1]){
					++i;
					break;
				}
			}
		}

		ElemType *p,*q;
		q=&(L->elem[i]);                 //q为插入位置
		for(p=&(L->elem[L->length-1]);p>=q;--p)
		  *(p+1)=*(p);                       //插入位置及之后元素右移
		*q=e;                               //插入e
		++L->length;                        //表长增1
		return OK;
}

Status InitList_Sq(SqList *L);
Status Insert_Sq(SqList *L,ElemType e);

int main(){
	SqList *L,List;
	L=&List;

	InitList_Sq(L);        //初始化
	int i;
	for(i=0;i<20;i++){
		L->elem[i]=2*i;
		L->length++;
	}

	printf("Before insert:\n");//插入前
	for(i=0;i<L->length;i++)
	  printf("%d\t",L->elem[i]);
	printf("\n");

	Insert_Sq(L,13);
	Insert_Sq(L,-1);
	Insert_Sq(L,100);
	
	printf("After insert:\n");//插入后
	for(i=0;i<L->length;i++)
	  printf("%d\t",L->elem[i]);
	printf("\n");
	
	return 0;
}//main functios

