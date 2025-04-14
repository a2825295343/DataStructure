#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ERROR 0
#define OK 1
typedef int ElemType;   //�������ͣ����޸�

// 1����̬�洢˳���ṹ����
#define ListSize 100    //���������
typedef struct {
    ElemType data[ListSize];    //�洢�ռ�
    int length;         //��ǰԪ�ظ���
} SeqList;

// 2����̬�洢˳���ṹ����
#define LIST_INIT_SIZE 12
#define LISTINCREMENT 4
typedef struct {
    ElemType* data;
    int length;
    int listsize;
} SqList;

//3-4��������ṹ����
typedef struct LNode {
    ElemType   data;       //������
    struct LNode* next;   //ָ����
}LNode, *LinkList;

//---------------------------��������Ϊ�㷨��������---------------------------

// 1����̬�洢˳�������������12��
void InitList1(SeqList& L);              //1����ʼ����LΪ�ձ�
void DestroyList1(SeqList& L);           //2���������Ա�L
void ClearList1(SeqList& L);             //3��������Ա�L
int ListEmpty1(SeqList L);               //4���ж����Ա�L�Ƿ�Ϊ��
int ListLength1(SeqList L);              //5�������Ա�L�ĳ���
ElemType GetElem1(SeqList L, int i);     //6����ȡ��L�е� i ��Ԫ��
int LocateELem1(SeqList L, ElemType e);  //7������ֵΪe��Ԫ�أ�������λ��
int IsIn1(SeqList L, ElemType x);        //8���ж�x�Ƿ��ڱ�L��
int NextElem1(SeqList L, ElemType x);    //9����x��ֱ�Ӻ��
int PriorElem1(SeqList L, ElemType x);   //10����x��ֱ��ǰ��
int ListInsert1(SeqList& L, int i, ElemType e); //11���ڵ� i ��Ԫ��ǰ����Ԫ�� e
int ListDelete1(SeqList& L, int i);      //12����˳���L��ɾ���� i ��Ԫ��

// 2����̬�洢˳�������������14��
int InitList2(SqList& L);                //1����ʼ����LΪ�ձ�
int DestroyList2(SqList& L);             //2���������Ա�L
int ClearList2(SqList& L);               //3��������Ա�L
int ListEmpty2(SqList L);                //4���ж����Ա�L�Ƿ�Ϊ��
int ListLength2(SqList L);               //5�������Ա�L�ĳ���
ElemType GetElem2(SqList L, int i);      //6����ȡ��L�е� i ��Ԫ��
int LocateElem2(SqList L, ElemType x);   //7������ֵΪx��Ԫ�أ�������λ��
int IsIn2(SqList L, ElemType x);         //8���ж�x�Ƿ��ڱ�L��
int NextElem2(SqList L, ElemType x);     //9����x��ֱ�Ӻ��
int PriorElem2(SqList L, ElemType x);    //10����x��ֱ��ǰ��
int ListInsert2(SqList& L, int i, ElemType e); //11���ڵ� i ��Ԫ��ǰ����Ԫ�� e
int ListDelete2(SqList& L, int i);       //12����˳���L��ɾ���� i ��Ԫ��
void Union2(SqList& A, SqList B);        //13�����ϵġ���������
void Intersection2(SqList& A, SqList B); //14�����ϵġ���������

// 3������ͷ���ĵ���������������12��
void InitList3(LinkList& first);         //1����ʼ��������firstΪ�ձ�
void DestroyList3(LinkList& first);      //2�����ٵ�����
void clear3(LinkList& first);            //3����յ�����
int ListEmpty3(LinkList first);          //4���жϵ������Ƿ�Ϊ��
int ListLength3(LinkList first);         //5��������ĳ���
ElemType GetElem3(LinkList first, int i); //6����ȡ�������е�i��Ԫ��
LinkList LocateElem3(LinkList first, ElemType x); //7������ֵΪx��Ԫ�أ�����ָ��
int IsIn3(LinkList first, ElemType x); //8���ж�x�Ƿ��ڵ�������
LinkList NextElem3(LinkList first, ElemType x);   //9����x��ֱ�Ӻ��
LinkList PriorElem3(LinkList first, ElemType x);  //10����x��ֱ��ǰ��
int ListInsert3(LinkList& first, int i, ElemType x); //11���ڵ� i ��Ԫ��ǰ����Ԫ�� x
int ListDelete3(LinkList& first, int i);  //12��ɾ���� i ��Ԫ��

// 4����ͷ���ĵ���������������15��
void InitList4(LinkList& first);          //1����ʼ����ͷ��㵥����firstΪ�ձ�
void DestroyList4(LinkList& first);       //2�����ٴ�ͷ��㵥����
void clear4(LinkList& first);             //3����մ�ͷ��㵥����
int ListEmpty4(LinkList first);           //4���жϴ�ͷ��㵥�����Ƿ�Ϊ��
int ListLength4(LinkList first);          //5�����ͷ��㵥����ĳ���
ElemType GetElem4(LinkList first, int i); //6����ȡ��ͷ��㵥�����е�i��Ԫ��
LNode* LocateElem4(LinkList first, ElemType x);  //7������ֵΪx��Ԫ�أ�����ָ��
int LocateELem_L4(LinkList first, ElemType x);   //8������ֵΪx��Ԫ�أ�����λ�����
int IsIn4(LinkList first, ElemType x);    //9���ж�x�Ƿ��ڴ�ͷ��㵥������
LinkList NextElem4(LinkList first, ElemType x);  //10����x��ֱ�Ӻ��
LinkList PriorElem4(LinkList first, ElemType x); //11����x��ֱ��ǰ��
int ListInsert4(LinkList first, int i, ElemType x);  //12���ڵ� i ��Ԫ��ǰ����Ԫ�� x
int ListDelete4(LinkList first, int i);   //13��ɾ���� i ��Ԫ��
LinkList createListF4(void);              //14��������ͷ��㵥�����û��������ݣ��ӵ�һ����ʼ�����
LinkList createListR4(void);              //15��������ͷ��㵥�����û��������ݣ������һ����ʼ��ǰ��


//---------------------------��������Ϊ��ӡ��������---------------------------

void printList1(SeqList L);        //��ӡ��̬�洢˳���
void printList2(SqList L);         //��ӡ��̬�洢˳���
void printList3(LinkList first);   //��ӡ����ͷ��㵥����
void printList4(LinkList first);   //��ӡ��ͷ��㵥����
#endif
