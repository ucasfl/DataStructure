//3.22
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
//判断栈空
int IsStackEmpty(SqStack *s){
	if(s->top == 0) return OK;
	else return ERROR;
}

#define OPSETSIZE 6
char OPSET[OPSETSIZE]={'+' , '-' , '*' , '/','(',')' };
unsigned char Prior[OPSETSIZE][OPSETSIZE] = {
	'=','=','<','<','<','<',
	'=','=','<','<','<','<',
	'>','>','=','=','<','<',
	'>','>','=','=','<','<',
	'>','>','>','>',' ',' ',
	'>','>','>','>',' ',' '
};
//测试Test是否是运算符
Status In(char Test, char* TestOp)
{
for (int i=0; i< OPSETSIZE; i++) {
    if (Test == TestOp[i])
        return OK;}
 return ERROR;
}

int ReturnOpOrd(char op, char* TestOp) {
for(int i=0; i< OPSETSIZE; i++) {
    if (op == TestOp[i])
            return i; }
return 0;
}

//返回两算符之间的优先关系
void Precede(char Aop, char Bop,char *result){
	int i,j;
	i=ReturnOpOrd(Aop,OPSET);
	j=ReturnOpOrd(Bop,OPSET);
	*result=Prior[i][j];
}
//转化为逆波兰表达式
Status Trans(ElemType *s){
	char *c=s;
	char e,result;
	SqStack OpStack,*p;//OpStack为运算符栈
	p=&OpStack;
	InitStack(p);
	while(*c!='#'){
		if(!In(*c,OPSET))//单字母变量，直接输出
		  printf("%c ",*c);
		else{//为运算符
			if(*c=='(')//左括号直接入栈
			{
				Push(p,*c);
				c++;
				continue;
			}
			else if(*c==')'){//右括号，把括号中的运算符输出
				Pop(p,&e);
				while(e!='(')
				  printf("%c ",e),Pop(p,&e);
				c++;
				continue;
			}
			else{
				int i=Pop(p,&e);//栈空
				if(i==ERROR){
					Push(p,*c);
					c++;
					continue;
				}
				if(e=='('){//栈顶为左括号，直接入栈
					Push(p,e),Push(p,*c),c++;
					continue;
				}
				Precede(e,*c,&result);
				if(result=='<')//运算符优先级高于栈顶元素，直接入栈
				  Push(p,e),Push(p,*c);
				else{   //低于栈顶元素，输出所有比它大的
					printf("%c ",e);
				    int i=Pop(p,&e);
					if(i==ERROR){
						Push(p,*c),c++;
						continue;
					}
					else{
						Precede(e,*c,&result);
						if(result=='>'||result=='=')
						  printf("%c ",e);
						while(result=='>'||result=='='&&!IsStackEmpty(p)){
						 int a= Pop(p,&e);
						 if(a==ERROR)   //栈空
						   break;
						  Precede(e,*c,&result),printf("%c ",e);
						}
						if(result=='>')//栈已经空
						  Push(p,*c);
						else //入栈
						  Push(p,e),Push(p,*c);
					}
				}
			}
		}
		c++;
	}
	while(!IsStackEmpty(p))
	  Pop(p,&e),printf("%c ",e);
	return OK;
}

Status InitStack(SqStack *s);
Status Push(SqStack *s,ElemType e);
Status Pop(SqStack *s,char *e);
Status In(char Test, char* TestOp);
int ReturnOpOrd(char op, char* TestOp);
void Precede(char Aop, char Bop,char *result);
Status Trans(ElemType *s);

//main函数
int main(){
	char *str;
	str=(char *)malloc(30*sizeof(char));
	printf("Please enter nomal expression,end with '#'\n");
	scanf("%s",str);
	printf("RePN is:\n");
	Trans(str);
	printf("\n");
	return 0;
}
