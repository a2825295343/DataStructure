#include "�ṹ���������弰��������.h"

//1����ʼ��
void InitList4(LinkList &first) {
    //��ʼ����ͷ���ĵ�����firstΪ�ձ�
    first = (LNode*)malloc(sizeof(LNode));   //����ͷ��� 
    first->next = NULL;
}

//2������
void  DestroyList4(LinkList& first) {
    //ɾȥ��ͷ�ڵ㵥����first�е����н�㣬����ͷ���
    LNode* q;
    while (first) {
        //��������ʱ��ѭ�����ɾȥ���н��
        q = first;
        first = first->next;
        free(q);        //�ͷ� 
    }
}

//3�����
void clear4(LinkList& first) {      // ��������Ϊ�ձ� 
    //ɾȥ��ͷ��㵥����first�е����н�㣬����ͷ���
    LNode* p, * q = first->next;
    while (q) {                   //��������ʱ��ѭ�����ɾȥ���н��
        p = q; q = q->next;
        free(p);                   //�ͷ� 
    };
    first->next = NULL;      //ͷ���ָ����Ϊ�� 
}

//4���ж������Ƿ�Ϊ��
int  ListEmpty4(LinkList first)
{                        //����ͷ��㵥����firstΪ�շ���1,���򷵻�0
    return  !(first->next);
}

//5��������ĳ���
int ListLength4(LinkList first) //�������ش�ͷ��㵥����first����
{
    LinkList p, q;
    p = first->next;
    int count = 0;
    while (p)
    {
        p = p->next;     count++;
    }
    return count;
}

//6����ȡ�����е�i��Ԫ��
ElemType GetElem4(LinkList first, int i) {
    //�������ش�ͷ��㵥����first��i��Ԫ��ֵ�������ڷ���NULL
    LinkList p;        
    int j;
    p = first->next;  j = 1;
    while (p && (j < i)) {                            //�ҵ�i��Ԫ��
        p = p->next; ++j;
    }
    if (!p || j > i) return NULL;                   //��i��Ԫ�ز�����
    return p->data;
}

//7������ֵΪx��Ԫ�أ�����ָ��
LNode* LocateElem4(LinkList first, ElemType x) { //�ڴ�ͷ��㵥//����first��������ֵΪx�Ľ�㣬���ҳɹ�����xλ�ã����򷵻�NULL
    LNode* p = first->next;                //ָ�� p ָʾ��һ�����
    while (p && (p->data != x))
        p = p->next;
    return p;
}

//8���ڴ�ͷ��㵥�����в���ֵΪx��Ԫ�أ�����λ�����
int LocateELem_L4(LinkList first, ElemType x) {
    //����L��ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0 
    LNode* p = first->next; int j = 1;
    while (p && p->data != x)
    {
        p = p->next;  j++;
    }
    if (p) return j;
    else return 0;
}

//9����x�ڴ�ͷ��㵥����first�к�������1���򷵻�0
int IsIn4(LinkList first, ElemType x)
{                  //��x�ڴ�ͷ��㵥����first�к�������1���򷵻�0
    LNode* p = first->next;                       //ָ�� p ָʾ��һ�����
    while (p && (p->data != x))
        p = p->next;
    return !(p == NULL);
}

//10����ͷ��㵥����first��x��ֱ�Ӻ�̵Ľ���ַ��û�з���NULL
LinkList NextElem4(LinkList first, ElemType x) { //�������ش�ͷ��㵥����first��x��ֱ�Ӻ�̵Ľ���ַ��û�з���NULL
    LinkList p = first->next;
    while (p && p->data != x)                            //��x
        p = p->next;
    if (!p || !p->next) return NULL;            //û��ֱ�Ӻ�� 
    return  p->next;
}

//11����ͷ��㵥����first��x��ֱ��ǰ���Ľ���ַ��û�з���NULL
LinkList PriorElem4(LinkList first, ElemType x) { //�������ش�ͷ��㵥����first��x��ֱ��ǰ���Ľ���ַ��û�з���NULL
    LinkList  p = first->next;
    while (p && p->next && (p->next->data != x))                    //��x
        p = p->next;
    if (!p || !p->next) return NULL;                          //û��ֱ��ǰ�� 
    return  p;
}

//12���ڵ� i ��Ԫ�ؽ��ǰ����Ԫ�� x
int ListInsert4(LinkList first, int i, ElemType x) {
    //�ڴ�ͷ�ڵ�ĵ�����first�е� i ��Ԫ�ؽ��ǰ����Ԫ�� x���ɹ�����OK���򷵻�ERROR
    LNode* p = first;   int k = 0;
    while (p && k < i - 1)
    {
        p = p->next;  k++;
    }                                               //Ѱ�ҵ� i-1����� 
    if (!p || i < 1)  {
        //printf("��Ч�Ĳ���λ��!\n");                      //��ֹ����
        return ERROR;
    }                                                 //����iֵ��������ERROR
    LNode* newnode = (LNode*)malloc(sizeof(LNode));       //�����½��
    newnode->data = x;
    newnode->next = p->next;                                   //�����½��
    p->next = newnode;
    return OK;
}

//13��ɾ�� i ��Ԫ�أ��ɹ�����OK���򷵻�ERROR
int ListDelete4(LinkList first, int i) {
    //ɾ����ͷ�ڵ㵥����first�ĵ� i ��Ԫ�أ��ɹ�����OK���򷵻�ERROR
    LinkList q;
        LNode* p = first; int k = 0;
    while (p && k++ < i - 1)  p = p->next;   //Ѱ�ҵ�i-1�����
    if (!p || !(p->next) || i < 1)
        return ERROR;                 //iֵ������(����0��С��0����)��ձ�	
    q = p->next;
    p->next = q->next; //ɾ�����
    free(q);  //�ͷ�
    return OK;
}

//14��������ͷ��㵥�����û��������ݣ��ӵ�һ����ʼ�����,ÿ������֮���ÿո�������س�����
LinkList createListF4(void) {
    //������ͷ��㵥������������
    LNode* first = (LinkList)malloc(sizeof(LNode)); //�������ͷָ��
    LNode* r = first;                               //������ͷ��㣬r ָ���β
    char ch;
    while ((ch = getchar()) != '\n') {
        LNode* q = (LNode*)malloc(sizeof(LNode));
        q->data = ch;                             //�����½��
        r->next = q;   r = q;                     //���뵽��ĩ��
    }
    r->next = NULL;
    return first;
}

//15��������ͷ��㵥�����û��������ݣ������һ����ʼ��ǰ��,ÿ������֮���ÿո�������س�����
LinkList createListR4(void) {//������ͷ��㵥������������
    //�������ͷָ��
    LNode* first = (LinkList)malloc(sizeof(LNode)); //������ͷ���
    first->next = NULL;
    char ch;
    while (( ch = getchar()) != '\n') {
        LNode* q = (LNode*)malloc(sizeof(LNode));
        q->data = ch;                          //�����½��
        q->next = first->next;                    //���뵽��ǰ��
        first->next = q;
    }
    return first;
}

//��ӡ��ͷ��㵥����first
void printList4(LinkList first) {
	LNode* p = first->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}