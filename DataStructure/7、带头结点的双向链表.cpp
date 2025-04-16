#include "�ṹ���������弰��������.h"

//˫���ѭ������ܶຯ���뵥�������ƣ��Ͳ�д�ˣ�doge��

//1����ʼ����LΪ�ձ�
void InitList7(DuLinkList& L) {
    L = (DuLNode*)malloc(sizeof(DuLNode));   //����ͷ��� 
    L->prior = NULL;
    L->next = NULL;
}

//2����������L
void DestroyList7(DuLinkList& L) {
    DuLNode* q;
    while (L) {
        //��������ʱ��ѭ�����ɾȥ���н��
        q = L;
        L = L->next;
        free(q);        //�ͷ� 
    }
}

//3���������L
void ClearList7(DuLinkList& L) {
    DuLNode* p, * q = L->next;
    while (q) {                   //��������ʱ��ѭ�����ɾȥ���н��
        p = q; q = q->next;
        free(p);                   //�ͷ� 
    };
    L->next = NULL;      //ͷ���ָ����Ϊ�� 
}

//4����������L�ĳ���
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

//5����ȡ����L�е�i��Ԫ�أ�����ָ��
DuLinkList GetElemP7(DuLinkList L, int i) {
    DuLinkList p;
    int j;
    p = L->next;  j = 1;
    while (p && (j < i)) {                            //�ҵ�i��Ԫ��
        p = p->next; ++j;
    }
    if (!p || j > i) return NULL;                   //��i��Ԫ�ز�����
    return p;
}

//6���ڵ� i ��Ԫ�ؽ��ǰ����Ԫ�� e
Status ListInsertF7(DuLinkList L, int i, ElemType e) {
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
	if (newnode->next) {newnode->next->prior = newnode;}
    return OK;
}

//7���ڵ�i����������½��
Status ListInsertR7(DuLinkList L, int i, ElemType e)
{   //�ڵ�i����������½��
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

//8��ɾ����i���
Status ListDelete7(DuLinkList L, int i, ElemType& e)
{ //ɾ����i���
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

//��ӡ��ͷ���˫������L
void printList7(DuLinkList L) {
    DuLNode* p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}