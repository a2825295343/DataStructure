#include "�ṹ���������弰��������.h"

//1����ʼ����LΪ�ձ�
void InitList8(DuLinkList& L)  //��ʼ��
{
    L = (DuLinkList)malloc(sizeof(DuLNode));
    if (L)
        L->next = L->prior = L;
    else
        exit(OVERFLOW);
}

//2����������L
void DestroyList8(DuLinkList& L)
{ // ����
    ClearList8(L);
    free(L);
    L = NULL;
}

//3���������L
void ClearList8(DuLinkList L) //���
{
    DuLinkList p = L->next;
    while (p != L)
    {
        p = p->next;
        free(p->prior);
    }
    L->next = L->prior = L;
}

//4���ж�����L�Ƿ�Ϊ��
Status ListEmpty8(DuLinkList L)
{
    if (L->next == L && L->prior == L)
        return TRUE;
    else
        return FALSE;
}

//5��������L�ĳ���
int ListLength8(DuLinkList L)
{  //�󳤶�
    int i = 0;
    DuLinkList p = L->next;
    while (p != L)
    {
        i++;
        p = p->next;
    }
    return i;
}

//6����ȡ����L�е�i��Ԫ�أ���ֵ��e
Status GetElem8(DuLinkList L, int i, ElemType& e)
{  //ȡ��i����ֵ
    int j = 1;
    DuLinkList p = L->next;
    while (p != L && j < i)
    {
        j++;
        p = p->next;
    }
    if (p == L || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

//7������Ԫ��e��λ�� 
int LocateElem8(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ // ����Ԫ��e��λ�� 

    int i = 0;
    DuLinkList p = L->next;
    while (p != L)
    {
        i++;
        if (compare(p->data, e))
            return i;
        p = p->next;
    }
    return 0;
}

//8��ȡcur_e��ֱ�Ӻ��
Status NextElem8(DuLinkList L, ElemType cur_e, ElemType& next_e)
{//ȡ���
    DuLinkList p = L->next->next;
    while (p != L)
    {
        if (p->prior->data == cur_e)
        {
            next_e = p->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

//9��ȡcur_e��ֱ��ǰ��
Status PriorElem8(DuLinkList L, ElemType cur_e, ElemType& pre_e)
{   //ȡǰ��
    DuLinkList p = L->next->next;
    while (p != L)
    {
        if (p->data == cur_e)
        {
            pre_e = p->prior->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

//10��ȡ��i����ַ
DuLinkList GetElemP8(DuLinkList L, int i)
{   //  /ȡ��i����ַ
    int j;
    DuLinkList p = L;
    if (i<0 || i>ListLength8(L))
        return NULL;
    for (j = 1; j <= i; j++)
        p = p->next;
    return p;
}

//11���ڵ� i ��Ԫ�ؽ��ǰ����Ԫ�� e
Status ListInsertF8(DuLinkList L, int i, ElemType e) {
    //�ڴ�ͷ�ڵ�ĵ�����first�е� i ��Ԫ�ؽ��ǰ����Ԫ�� e���ɹ�����OK���򷵻�ERROR
    DuLNode* p = L;   int k = 0;
    while (p && k < i - 1)
    {
        p = p->next;  k++;
    }                                               //Ѱ�ҵ� i-1����� 
    if (!p || i < 1) {
        //printf("��Ч�Ĳ���λ��!\n");                      //��ֹ����
        return ERROR;
    }                                                 //����iֵ��������ERROR
    DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));       //�����½��
    newnode->data = e;
    newnode->next = p->next;                           //�����½��
    p->next = newnode;
    newnode->prior = p;
    newnode->next->prior = newnode;
    return OK;
}

//12���ڵ� i ��Ԫ�ؽ������Ԫ�� e
Status ListInsertR8(DuLinkList L, int i, ElemType e)
{ //�ڵ�i�������e
    DuLinkList p, s;
    if (i<1 || i>ListLength8(L) + 1)
        return ERROR;
    p = GetElemP8(L, i);
    if (!p)
        return ERROR;
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (!s)
        return ERROR;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return OK;
}

//13��ɾ���� i ��Ԫ��
Status ListDelete8(DuLinkList L, int i, ElemType& e)
{ //ɾ����i���
    DuLinkList p;
    if (i < 1)
        return ERROR;
    p = GetElemP8(L, i);
    if (!p)
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

//14����ͷ��������L�е�Ԫ��
void ListTraverse8(DuLinkList L, void(*visit)(ElemType))
{     //��ͷָ�뿪ʼ�������
    DuLinkList p = L->next;
    while (p != L)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

//15����β��������L�е�Ԫ��
void ListTraverseBack8(DuLinkList L, void(*visit)(ElemType))
{ //��βָ�뿪ʼ��ǰ����
    DuLinkList p = L->prior;
    while (p != L)
    {
        visit(p->data);
        p = p->prior;
    }
    printf("\n");
}
