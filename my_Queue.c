#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// 链式结构：表示队列 

typedef int QDataType;
typedef struct QListNode 
{ 
	struct QListNode* _next; 
	QDataType _data; 
}QNode; 
 
// 队列的结构 
typedef struct Queue 
{ 
	QNode* _front; 
	QNode* _rear; 
}Queue; 
 
QNode* BuyQueueNode(QDataType data)
{
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if(tmp != NULL)
	{
		tmp->_data = data;
		tmp->_next = NULL;
		return tmp;
	}
}

// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	if(q->_front == NULL)
	{
		q->_front = q->_rear = BuyQueueNode(data);
	}
	else
	{
		QNode* curr = BuyQueueNode(data);
		q->_rear->_next = curr;
		q->_rear = curr;
	}
}


// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q->_front);
	QNode* tmp = q->_front->_next;
	free(q->_front);
	q->_front = tmp;
}


// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q->_front);
	return q->_front->_data;
}


// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q->_front);
	return q->_rear->_data;
}


// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* curr = q->_front;
	while(curr)
	{
		count++;
		curr = curr->_next;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL;
}


// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q->_front);
	while(q->_front)
	{
		QueuePop(q);
	}
}