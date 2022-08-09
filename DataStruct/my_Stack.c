#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFSTACKSIZE 100

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

void CheckCapacity(Stack* ps)
{
	if(ps->_top >= ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity*sizeof(STDataType));
	}
}

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = (STDataType*)malloc(DEFSTACKSIZE*sizeof(STDataType));
	ps->_top = 0;
	ps->_capacity = DEFSTACKSIZE;
}


// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top-1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}


// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0;
}


// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	if(ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = ps->_capacity = 0;
		}
}