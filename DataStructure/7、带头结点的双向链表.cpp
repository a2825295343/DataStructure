#include "结构、常量定义及函数声明.h"

//双向非循环链表很多函数与单链表类似，就不写了（doge）

//1、初始化表L为空表
void InitList7(DuLinkList& L) {
    L = (DuLNode*)malloc(sizeof(DuLNode));   //创建头结点 
    L->prior = NULL;
    L->next = NULL;
}

//2、销毁链表L
void DestroyList7(DuLinkList& L) {
    DuLNode* q;
    while (L) {
        //当链不空时，循环逐个删去所有结点
        q = L;
        L = L->next;
        free(q);        //释放 
    }
}

//3、清空链表L
void ClearList7(DuLinkList& L) {
    DuLNode* p, * q = L->next;
    while (q) {                   //当链不空时，循环逐个删去所有结点
        p = q; q = q->next;
        free(p);                   //释放 
    };
    L->next = NULL;      //头结点指针域为空 
}

//4、计算链表L的长度
int ListLength7(DuLinkList L) {
    DuLinkList p, q;
    p = L->next;
    int count = 0;
    while (p)
    {
        p = p->next;     count++;
    }
    return count;
}

//5、获取链表L中第i个元素，返回指针
DuLinkList GetElemP7(DuLinkList L, int i) {
    DuLinkList p;
    int j;
    p = L->next;  j = 1;
    while (p && (j < i)) {                            //找第i个元素
        p = p->next; ++j;
    }
    if (!p || j > i) return NULL;                   //第i个元素不存在
    return p;
}

//6、在第 i 个元素结点前插入元素 e
Status ListInsertF7(DuLinkList L, int i, ElemType e) {
    //在带头节点的单链表first中第 i 个元素结点前插入元素 e，成功返回OK否则返回ERROR
    DuLNode* p = L;   int k = 0;
    while (p && k < i - 1)
    {
        p = p->next;  k++;
    }                                               //寻找第 i-1个结点 
    if (!p || i < 1) {
        //printf("无效的插入位置!\n");                      //终止插入
        return ERROR;
    }                                                 //参数i值不合理返回ERROR
    DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));       //创建新结点
    newnode->data = e;
    newnode->next = p->next;                           //插入新结点
    p->next = newnode;
	newnode->prior = p;
	if (newnode->next) {newnode->next->prior = newnode;}
    return OK;
}

//7、在第i结点后面插入新结点
Status ListInsertR7(DuLinkList L, int i, ElemType e)
{   //在第i结点后面插入新结点
    DuLinkList p, s;
    if (i<1 || i>ListLength7(L) + 1)
        return ERROR;
    p = GetElemP7(L, i);
    if (!p)
        return ERROR;
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (!s)
        return ERROR;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    if(p->next){ p->next->prior = s; }
    p->next = s;
    return OK;
}

//8、删除第i结点
Status ListDelete7(DuLinkList L, int i, ElemType& e)
{ //删除第i结点
    DuLinkList p;
    if (i < 1)
        return ERROR;
    p = GetElemP7(L, i);
    if (!p)
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    if (p->next) { p->next->prior = p->prior; }
    free(p);
    return OK;
}

//打印带头结点双向链表L
void printList7(DuLinkList L) {
    DuLNode* p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}