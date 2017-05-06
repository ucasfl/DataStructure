//3.31
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
//Push 元素进栈
Status Push(SqStack *s,ElemType e){
	if(s->top >= s->stacksize) {//若栈已满,则增加INCREMENTSIZE 个存储单元
		s->base=(ElemType *)realloc(s->base,(s->stacksize + INCREMENTSIZE)*sizeof(ElemType));
		if(!s->base) return ERROR;  //存储分配失败
		s->stacksize+=INCREMENTSIZE;
	}
	s->base[s->top++]=e; //e成为新的栈顶元素,栈顶指针加1
	return OK;
}

//Pop 元素出栈
Status Pop(SqStack *s,char *e){
	if(s->top==0) return ERROR; // 栈空,返回出错标志
	*e=s->base[--s->top]; // 等于s->top--; *e=s->base[s->top];
	return OK;
}
int IsStackEmpty(SqStack *s){
	if(s->top == 0) return OK;
	else return ERROR;
}

Status Judge(char *str){
	char *c=str;
	int i=0;
	char e,s[100];
	SqStack p;
	InitStack(&p);
	while(*c!='@')//先将元素压入栈中和字符串数组中
	  Push(&p,*c),s[i++]=*c,c++;
	Pop(&p,&e),i=0;
	while(!IsStackEmpty(&p)){
		if(e!=s[i++])//正倒不同
		  return ERROR;
		Pop(&p,&e);
	}
	return OK;
}

Status InitStack(SqStack *s);
Status Push(SqStack *s,ElemType e);
Status Pop(SqStack *s,char *e);
int IsStackEmpty(SqStack *s);
Status Judge(char *str);
//main函数
int main(){
	char *str;
	str=(char *)malloc(30*sizeof(char));
	scanf("%s",str);
	int result=Judge(str);
	printf("%s\n",(result==1)?"Is Huiwen!":"Not Huiwen!");
	return 0;
}
