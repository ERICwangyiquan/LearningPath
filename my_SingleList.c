#include <stdio.h>
#include <assert.h>
#include<stdlib.h>

typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
    SListNode* next = (SListNode*) malloc(sizeof(SListNode));
    next->data=x;
    next->next=NULL;
    return next;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
    assert(plist);
    SListNode* curr = plist;
    while(curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    SListNode* newNode = BuySListNode(x);
    if(*pplist==NULL)
    {
        *pplist = newNode;
    }
    else
    {
        SListNode* tail = *pplist;
        while(tail->next!=NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    SListNode* newNode = BuySListNode(x);
    assert(pplist);
    newNode->next = *pplist;
   *pplist = newNode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
    assert(pplist);
    SListNode* curr = *pplist;
    while(curr->next->next)
    {
        curr = curr->next;
    }
    free(curr->next);
    curr->next=NULL;
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
    assert(*pplist);
    SListNode* cur  = *pplist;
    *pplist = (*pplist)->next;
    free(cur);
    cur = NULL;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    assert(plist);
    SListNode* curr = plist;
    while(curr!=NULL)
    {
        if(curr->data == x)
            return curr;
        else
            curr = curr->next;
    }
    return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* curr= pos->next;
    SListNode* tmp = BuySListNode(x);
    pos->next = tmp;
    tmp->next = curr;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
    SListNode* tmp = pos->next;
    pos->next = pos->next->next;
    free(tmp);
    tmp = NULL;
}
// destroy
void SListDestory(SListNode* plist)
{
    assert(plist);
    SListNode* head = plist;
    while(head)
    {
        SListNode* curr = head;
        head = head->next;
        free(curr);
        curr=NULL;
    }
}



SListNode* Reverse(SListNode** pplist)
{
    assert(pplist);
    SListNode* curr = *pplist, *prev = NULL;
    while(curr)
    {
        SListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev;

}

int main()
{
    SListNode* head = NULL;
    SListPushFront(&head,1);
    SListPushFront(&head,2);
    SListPushFront(&head,2);
    SListPushFront(&head,3);
    SListPushFront(&head,4);

    // SListPushBack(&head, 1);
    // SListPushBack(&head, 2);
    // SListPushBack(&head, 3);
    // SListPushBack(&head, 4);
    // SListPushBack(&head, 5);

    SListPrint(head);
    head = Reverse(&head);
    // SListPopBack(&head);
    // SListPopBack(&head);
    // SListPopBack(&head);
    SListPrint(head);
    return 0;
}