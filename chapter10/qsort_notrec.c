//10.30
#include<stdio.h>
#include<stdlib.h>

#define MAX 200
#define INITSIZE 100 // 栈空间初始分配量
#define INCREMENTSIZE 10 // 栈空间分配增量
#define OK 1
#define ERROR 0
typedef struct{
	int low;
	int high;
} ElemType ;
typedef int Status;

typedef struct {
	int top;// 栈顶指针
    ElemType *base; // 栈不存在时值为 NULL
	int stacksize ;  //当前已分配空间

}SqStack ;

typedef struct{
	int r[MAX];
	int length;
}List;

Status InitStack(SqStack *s);
Status Push(SqStack *s,ElemType e);
Status Pop(SqStack *s, ElemType *e);
int IsStackEmpty(SqStack *s);
void qsort_notrec( List *L );
int seperate( List *L, int low, int high );
void three_sort(List *L, int low, int high);

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
Status Pop(SqStack *s, ElemType *e){
	if(s->top==0) return ERROR; // 栈空,返回出错标志
	*e=s->base[--s->top]; // 等于s->top--; *e=s->base[s->top];
	return OK;
}
//判断栈空
int IsStackEmpty(SqStack *s){
	if(s->top == 0) return OK;
	else return ERROR;
}

void qsort_notrec(List *L){
	int low = 1, high = L->length;
	SqStack S;
	InitStack(&S);//initial the stack S
	while ( low < high || !IsStackEmpty(&S) ) {
		if ( high - low > 2 ){
			int middle = seperate( L, low, high ); //seperate into two list
			if (high - middle > middle - low){ //push the longest part into stack
				ElemType e;
				e.low = middle + 1;
				e.high = high;
				Push( &S, e );
				high = middle;
			}
			else{ // push the first part's bandary into stack
				ElemType e;
				e.low = low;
				e.high = middle;
				Push ( &S, e );
				low = middle + 1;
			}
		}//if 
		else if ( low < high && high - low < 3 ){
			three_sort( L, low, high );//three two or three record
			low = high; //imply the list has sorted
		}
		else { //get another not sorted list to sort
			ElemType a;
			Pop( &S, &a );
			low = a.low;
			high = a.high;
		}
	}//while
}//qsort_notrec

int seperate( List *L, int low, int high ){//seperate the record into two part
	L->r[0] = L->r[low];
	while ( low < high ){
		while ( low < high && L->r[high] >= L->r[0] ) {
			high --;
		}
		L->r[low] = L->r[high];
		while ( low < high && L->r[low] <= L->r[0] ) {
			low ++;
		}
		L->r[high] = L->r[low];
	}//while
	L->r[low] = L->r[0];
	return low; //low is the middle record's index
}

void three_sort( List *L, int low, int high ){
	int a, b, c;
	if (low == high -1){
		a = L->r[low];
		b = L->r[high];
		L->r[low] = (a < b)?a:b;
		L->r[high] = (a > b)?a:b;
	}
	else{
		a = L->r[low];
		b = L->r[low + 1];
		c = L->r[low + 2];
		if( a > b ){
			if ( b > c ){
				L->r[low] = c;
				L->r[low + 1] = b;
				L->r[high] = a;
			}
			else if ( a > c ){
				L->r[low] = b;
				L->r[low + 1] = c;
				L->r[high] = a;
			}
			else{
				L->r[low] = b;
				L->r[low + 1] = a;
				L->r[high] = c;
			}
		}
		else{
			if (a > c){
				L->r[low] = c;
				L->r[low + 2] = a;
				L->r[high] = b;
			}
			else if(b > c){
				L->r[low] = a;
				L->r[low + 1] = c;
				L->r[high] = b;
			}
			else{
				L->r[low] = a;
				L->r[low + 1] = b;
				L->r[high] = c;
			}
		}
	}
}

int main( int argc, char **argv ) {
	List L;
	printf( "Input length: " );
	scanf("%d", &(L.length));
	printf( "Input record: " );
	for ( int i = 1; i <= L.length; i++ ) {
		scanf("%d", &(L.r[i]));
	}
	qsort_notrec(&L);
	for ( int i = 0; i < L.length; i++ ) {
		printf( "%d\n", L.r[i + 1] );
	}
	return 0;
}
