#include "结构、常量定义及函数声明.h"

//1、初始化表L为空表
void InitList6(LinkList& L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        exit(OVERFLOW);
    L->next = L;
}

//2、销毁链表L
void DestroyList6(LinkList& L)
{
    ClearList6(L);
    free(L);
    L = NULL;
}

//3、清空链表L
void ClearList6(LinkList& L)
{
    LinkList p, q;
    L = L->next;
    p = L->next;
    while (p != L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = L;
}

//4、判断链表L是否为空
Status ListEmpty6(LinkList L)
{
    if (L->next == L)
        return TRUE;
    else
        return FALSE;
}

//5、求链表L的长度
int ListLength6(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while (p != L)
    {
        i++;   p = p->next;
    }
    return i;
}

//6、获取链表L中第i个元素
Status GetElem6(LinkList L, int i, ElemType& e)
{
    int j = 1;
    LinkList p = L->next->next;
    if (i <= 0 || i > ListLength6(L))
        return ERROR;
    while (j < i)
    {
        j++;  p = p->next;
    }
    e = p->data;
    return OK;
}

//7、查找值为e的元素，返回其位序
int LocateElem6(LinkList L, ElemType e)
{
    int i = 0;
    LinkList p = L->next->next;
    while (p != L->next)
    {
        i++;
        if (p->data == e)
            return i;
        p = p->next;
    }
    return 0;
}

//8、求cur_e的直接后继
Status NextElem6(LinkList L, ElemType cur_e, ElemType& next_e)
{
    LinkList p = L->next->next;
    while (p != L)
    {
        if (p->data == cur_e)
        {
            next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

//9、求cur_e的直接前驱
Status PriorElem6(LinkList L, ElemType cur_e, ElemType& pre_e)
{

    LinkList q, p = L->next->next;
    q = p->next; //q是p的下一个
    while (q != L->next)
    {
        if (q->data == cur_e)
        {
            pre_e = p->data; //p是q的前驱
            return OK;
        }
        p = q;
        q = q->next;
    }
    return ERROR;
}

//10、在第 i 个元素结点前插入元素 e
Status ListInsert6(LinkList& L, int i, ElemType e)
{
    LinkList p = L->next, q;
    int j = 0;
    if (i <= 0 || i > ListLength6(L) + 1)
        return ERROR;
    while (j < i - 1)
    {
        j++;
        p = p->next;
    }
    q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    if (p == L)
        L = q;
    return OK;
}

//11、删除第 i 个元素，把删除的元素值赋给e
Status ListDelete6(LinkList& L, int i, ElemType& e)
{
    LinkList q, p = L->next;
    int j = 0;
    if (i <= 0 || i > ListLength6(L))
        return ERROR;
    while (j < i - 1)
    {
        j++;
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    e = q->data;
    if (L == q)
        L = p;
    free(q);
    return OK;
}

//12、遍历链表L中的元素，visit为函数指针，指向打印函数
void ListTraverse6(LinkList L, void(*visit)(ElemType))
{
    LinkList p = L->next->next;
    while (p != L->next)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}
