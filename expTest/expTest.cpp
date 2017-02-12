// expTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <stdlib.h>

#define MAX_STRING_VAL 15
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct stSElemType
{
	char stringval[MAX_STRING_VAL];
	int type;
}SElemType;

typedef struct stStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
enum Status
{
	OK=0,
	ERROR=1
};
Status InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == S.base) return ERROR;
	e = S.top - 1;
	return OK;
}

Status Push(SqStack *S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S->base) exit(1);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base) return ERROR;
	e = --S->top;
	return OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Status a;
	a = OK;
	system("pause");
	return 0;
}

