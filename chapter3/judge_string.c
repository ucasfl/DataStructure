//3.17
#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 100 // 栈空间初始分配量
#define INCREMENTSIZE 10 // 栈空间分配增量
#define OK 1
#define ERROR 0
typedef char ElemType ;
typedef int Status;

typedef struct {
	int top;// 栈顶指针
    ElemType *base; // 栈不存在时值为 NULL
	int stacksize ;  //当前已分配空间

}SqStack ;

Status InitStack(SqStack *s){// 构造一个空栈 s
	s->base=(ElemType *)malloc(INITSIZE * sizeof(ElemType));
	if (!s) return ERROR;
	s->top=0;
	s->stacksize=INITSIZE;
	return OK;
}
//push 元素进栈
Status Push(SqStack *s,ElemType e){
	if(s->top >= s->stacksize) {//若栈已满,则增加INCREMENTSIZE 个存储单元
		s->base=(ElemType *)realloc(s->base,(s->stacksize + INCREMENTSIZE)*sizeof(ElemType));
		if(!s->base) return ERROR;  //存储分配失败
		s->stacksize+=INCREMENTSIZE;
	}
	s->base[s->top++]=e; //e成为新的栈顶元素,栈顶指针加1
	return OK;
}
//pop 元素出栈
Status Pop(SqStack *s,char *e){
	if(s->top==0) return ERROR; // 栈空,返回出错标志
	*e=s->base[--s->top]; // 等于s->top--; *e=s->base[s->top];
	return OK;
}
//判断栈空
int IsStackEmpty(SqStack *s){
	if(s->top == 0) return OK;
	else return ERROR;
}

Status Judge_Str(char *str){
	SqStack St,*q;
	q=&St;
	InitStack(q);
	char *c=str;
	while(*c!='&')//把序列１读入栈中
	  Push(q,*c),c++;
	c++;
	while(*c!='@'){  //读序列２看是否与序列１匹配
    	char a;
		int j=Pop(q,&a);
		if(j==ERROR) 
		  return ERROR;//栈空，不匹配
		if(a!=*c)//不匹配
		  return ERROR;
		c++;
	}
	int i=IsStackEmpty(q);
	if(i==ERROR) 
	  return ERROR;
	return OK;//匹配
}
//函数声明
Status InitStack(SqStack *s);
Status Pop(SqStack *s,char *e);
int IsStackEmpty(SqStack *s);
Status Judge_Str(char *str);
Status Push(SqStack *s,ElemType e);

//main函数测试
int main(){
	char *str=(char *)malloc(30*sizeof(char));
	scanf("%s",str);
	int judge=Judge_Str(str);
	if(judge==1)
	  printf("Correct!\n");
	else
	  printf("Wrong!\n");
	return 0;
}
