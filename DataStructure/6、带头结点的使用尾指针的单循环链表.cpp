#include "�ṹ���������弰��������.h"

//1����ʼ����LΪ�ձ�
void InitList6(LinkList& L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        exit(OVERFLOW);
    L->next = L;
}

//2����������L
void DestroyList6(LinkList& L)
{
    ClearList6(L);
    free(L);
    L = NULL;
}

//3���������L
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

//4���ж�����L�Ƿ�Ϊ��
Status ListEmpty6(LinkList L)
{
    if (L->next == L)
        return TRUE;
    else
        return FALSE;
}

//5��������L�ĳ���
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

//6����ȡ����L�е�i��Ԫ��
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

//7������ֵΪe��Ԫ�أ�������λ��
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

//8����cur_e��ֱ�Ӻ��
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

//9����cur_e��ֱ��ǰ��
Status PriorElem6(LinkList L, ElemType cur_e, ElemType& pre_e)
{

    LinkList q, p = L->next->next;
    q = p->next; //q��p����һ��
    while (q != L->next)
    {
        if (q->data == cur_e)
        {
            pre_e = p->data; //p��q��ǰ��
            return OK;
        }
        p = q;
        q = q->next;
    }
    return ERROR;
}

//10���ڵ� i ��Ԫ�ؽ��ǰ����Ԫ�� e
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

//11��ɾ���� i ��Ԫ�أ���ɾ����Ԫ��ֵ����e
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

//12����������L�е�Ԫ�أ�visitΪ����ָ�룬ָ���ӡ����
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
