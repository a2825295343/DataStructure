#include "�ṹ���������弰��������.h"

//1����ʼ��������firstΪ�ձ�
void InitList3(LinkList& first) {  //��ʼ��������firstΪ�ձ�
    first = NULL;
}

//2�����ٵ�����
void DestroyList3(LinkList& first) {
    //ɾȥ������first�����н��
    LNode* q;
    while (first) {
        //��������ʱ��ѭ�����ɾȥ���н��
        q = first; first = first->next;
        free(q);        //�ͷ� 
    }
}

//3����յ�����
void clear3(LinkList& first) {
    //ɾȥ������first�����н��
    LNode* q;
    while (first) {
        //��������ʱ��ѭ�����ɾȥ���н��
        q = first; first = first->next;
        free(q);        //�ͷ� 
    }
}

//4���ж������Ƿ�Ϊ��
int ListEmpty3(LinkList first)
{                        //��������firstΪ�շ���1,���򷵻�0
    return !first;
}

//5��������ĳ���
int ListLength3(LinkList first)   //����ֵΪ������first����
{
    LinkList p;
    p = first;
    int count = 0;
    while (p)
    {
        p = p->next;          count++;
    }
    return count;
}

//6����ȡ�����е�i��Ԫ�أ����ص�i��Ԫ��ֵ
ElemType GetElem3(LinkList first, int i)
{    //�������ص�����first�е�i��Ԫ��ֵ�������ڷ���NULL
    LinkList p;        int j;
    p = first; j = 1;
    while (p && (j < i)) {           //�ҵ�i��Ԫ��
        p = p->next; ++j;
    }
    if (!p || j > i) return NULL;  //��i��Ԫ�ز�����,p ��û�ҵ�
    //j>i  ������i<1�����
    return p->data;
}

//7����������ֵΪx�Ľ�㣬�ɹ�����x��һ�γ��ֵ�λ�ã����򷵻�NULL
LinkList LocateElem3(LinkList first, ElemType x) {//�ڵ�����first��
    //��������ֵΪx�Ľ�㣬�ɹ�����x��һ�γ��ֵ�λ�ã����򷵻�NULL
    LNode* p = first;                //ָ�� p ָʾ��һ�����
    while (p && (p->data != x))
        p = p->next;
    return p;
}

//8���ж�x�Ƿ��ڵ�������
int IsIn3(LinkList first, ElemType x)
{                             //��x�ڵ�����first�к�������1���򷵻�0
    LNode* p = first;                       //ָ�� p ָʾ��һ�����
    while (p && (p->data != x))        //��x
        p = p->next;
    return !(p == NULL);
}

//9����x��ֱ�Ӻ�̣�����ָ��
LinkList NextElem3(LinkList first, ElemType x) { //�������ص�����//first��ֵΪx����ֱ�Ӻ�̽���ַ��û�з���NULL
    LinkList p = first;
    while (p && p->data != x)                  //��x
        p = p->next;
    if (!p || !p->next) return NULL;            //û��ֱ�Ӻ�� 
    return  p->next;
}

//10����x��ֱ��ǰ��������ָ��
LinkList PriorElem3(LinkList first, ElemType x)
{          //��������x��ֱ��ǰ���Ľ���ַ��û�з���NULL
    LinkList  p = first;
    while (p && p->next && (p->next->data != x))  //��x��ֻҪx��
        //p��next��data����ô��ǰ������p
        p = p->next;
    if (!p || !p->next) return NULL;                  //û��ֱ��ǰ�� 
    return  p;
}

//11���ڵ� i ��Ԫ�ؽ��ǰ����Ԫ�� x
int ListInsert3(LinkList& first, int i, ElemType x) {
    //�ڵ�����first�е� i ��Ԫ�ؽ��ǰ����Ԫ�� x���ɹ�����1���򷵻�0
    LNode* newnode = (LNode*)malloc(sizeof(LNode));
    newnode->data = x;                                  //�����½��
    if (i == 1) {                                     //����Ϊ��һ�����
        newnode->next = first;                //�½���Ϊ��һ�����
        first = newnode;
        return OK;
    }
    LNode* p = first;   int k = 1;           //����λ�ò��ǵ�һ�����
        while (p && k < i - 1)
        {
            p = p->next;  k++;
        }   //�ƶ�ָ�룬�ҵ� i-1����� 
        if (!p || i < 1)  {
            printf("��Ч�Ĳ���λ��!\n");                //��ֹ����
            free(newnode);
            return ERROR;
     }
     newnode->next = p->next;
     p->next = newnode;                           //���ڱ��м��ĩβ
     return OK;
    }

//12��ɾ���� i ��Ԫ�أ��ɹ�����OK���򷵻�ERROR
int ListDelete3(LinkList& first, int i) {
    LNode* q;
    //�ڵ�����first��ɾ���� i ����㣬ɾ���ɹ�����1���򷵻�0
    if (first && i == 1)                        //ɾ�����е� 1 �����
    {
        q = first;  first = first->next;
    }
    else {
        LNode* p = first;   int k = 1;
        while (p && k < i - 1)
        {
            p = p->next; k++;
        }
        if (!p || !(p->next) || i < 1) {
            //�Ҳ�����i-1�����
            printf("��Ч��ɾ��λ��!\n");
            return ERROR;
        }
        else {
            q = p->next;            //ɾ���м����β���Ԫ��         
            p->next = q->next;
        }
    }
     free(q);
     return OK;                   //�ͷ�q
}

//��ӡ������first
void printList3(LinkList first) {
	LNode* p = first;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}