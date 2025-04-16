#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ERROR 0
#define OK 1
typedef int ElemType;   //�������ͣ����޸�
typedef int Status;   //״̬����ֵ���ͣ����޸ģ��볣��ERROR��OK��

//1����̬�洢˳���ṹ����
#define ListSize 100    //���������
typedef struct {
    ElemType data[ListSize];    //�洢�ռ�
    int length;         //��ǰԪ�ظ���
} SeqList;

//2����̬�洢˳���ṹ����
#define LIST_INIT_SIZE 12
#define LISTINCREMENT 4
typedef struct {
    ElemType* data;
    int length;
    int listsize;
} SqList;

//3-4��6��������ṹ����
typedef struct LNode {
    ElemType   data;       //������
    struct LNode* next;   //ָ����
}LNode, *LinkList;

//5����̬����ṹ����
#define MAX_SIZE 100 
typedef struct
{
    ElemType data; // ������   
    int cur; // �α��� 
}component, SLinkList[MAX_SIZE];

//7-8��˫������ṹ����
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode* prior, * next;
}DuLNode, *DuLinkList;


//---------------------------��������Ϊ�㷨��������---------------------------

//1����̬�洢˳�������������12��
void InitList1(SeqList& L);               //1����ʼ����LΪ�ձ�
void DestroyList1(SeqList& L);            //2���������Ա�L
void ClearList1(SeqList& L);              //3��������Ա�L
int ListEmpty1(SeqList L);                //4���ж����Ա�L�Ƿ�Ϊ��
int ListLength1(SeqList L);               //5�������Ա�L�ĳ���
ElemType GetElem1(SeqList L, int i);      //6����ȡ��L�е� i ��Ԫ��
int LocateELem1(SeqList L, ElemType e);   //7������ֵΪe��Ԫ�أ�������λ��
int IsIn1(SeqList L, ElemType x);         //8���ж�x�Ƿ��ڱ�L��
int NextElem1(SeqList L, ElemType x);     //9����x��ֱ�Ӻ��
int PriorElem1(SeqList L, ElemType x);    //10����x��ֱ��ǰ��
Status ListInsert1(SeqList& L, int i, ElemType e); //11���ڵ� i ��Ԫ��ǰ����Ԫ�� e
Status ListDelete1(SeqList& L, int i);    //12����˳���L��ɾ���� i ��Ԫ��

//2����̬�洢˳�������������14��
Status InitList2(SqList& L);              //1����ʼ����LΪ�ձ�
Status DestroyList2(SqList& L);           //2���������Ա�L
Status ClearList2(SqList& L);             //3��������Ա�L
int ListEmpty2(SqList L);                 //4���ж����Ա�L�Ƿ�Ϊ��
int ListLength2(SqList L);                //5�������Ա�L�ĳ���
ElemType GetElem2(SqList L, int i);       //6����ȡ��L�е� i ��Ԫ��
int LocateElem2(SqList L, ElemType x);    //7������ֵΪx��Ԫ�أ�������λ��
int IsIn2(SqList L, ElemType x);          //8���ж�x�Ƿ��ڱ�L��
int NextElem2(SqList L, ElemType x);      //9����x��ֱ�Ӻ��
int PriorElem2(SqList L, ElemType x);     //10����x��ֱ��ǰ��
Status ListInsert2(SqList& L, int i, ElemType e); //11���ڵ� i ��Ԫ��ǰ����Ԫ�� e
Status ListDelete2(SqList& L, int i);     //12����˳���L��ɾ���� i ��Ԫ��
void Union2(SqList& A, SqList B);         //13�����ϵġ���������
void Intersection2(SqList& A, SqList B);  //14�����ϵġ���������

//3������ͷ���ĵ���������������12��
void InitList3(LinkList& first);          //1����ʼ��������firstΪ�ձ�
void DestroyList3(LinkList& first);       //2�����ٵ�����
void clear3(LinkList& first);             //3����յ�����
int ListEmpty3(LinkList first);           //4���жϵ������Ƿ�Ϊ��
int ListLength3(LinkList first);          //5��������ĳ���
ElemType GetElem3(LinkList first, int i); //6����ȡ�������е�i��Ԫ��
LinkList LocateElem3(LinkList first, ElemType x); //7������ֵΪx��Ԫ�أ�����ָ��
int IsIn3(LinkList first, ElemType x); //8���ж�x�Ƿ��ڵ�������
LinkList NextElem3(LinkList first, ElemType x);   //9����x��ֱ�Ӻ��
LinkList PriorElem3(LinkList first, ElemType x);  //10����x��ֱ��ǰ��
Status ListInsert3(LinkList& first, int i, ElemType x); //11���ڵ� i ��Ԫ��ǰ����Ԫ�� x
Status ListDelete3(LinkList& first, int i);  //12��ɾ���� i ��Ԫ��

//4����ͷ���ĵ���������������15��
void InitList4(LinkList& first);           //1����ʼ����ͷ��㵥����firstΪ�ձ�
void DestroyList4(LinkList& first);        //2�����ٴ�ͷ��㵥����
void clear4(LinkList& first);              //3����մ�ͷ��㵥����
int ListEmpty4(LinkList first);            //4���жϴ�ͷ��㵥�����Ƿ�Ϊ��
int ListLength4(LinkList first);           //5�����ͷ��㵥����ĳ���
ElemType GetElem4(LinkList first, int i);  //6����ȡ��ͷ��㵥�����е�i��Ԫ��
LNode* LocateElem4(LinkList first, ElemType x);  //7������ֵΪx��Ԫ�أ�����ָ��
int LocateELem_L4(LinkList first, ElemType x);   //8������ֵΪx��Ԫ�أ�����λ�����
int IsIn4(LinkList first, ElemType x);    //9���ж�x�Ƿ��ڴ�ͷ��㵥������
LinkList NextElem4(LinkList first, ElemType x);  //10����x��ֱ�Ӻ��
LinkList PriorElem4(LinkList first, ElemType x); //11����x��ֱ��ǰ��
Status ListInsert4(LinkList first, int i, ElemType x);  //12���ڵ� i ��Ԫ��ǰ����Ԫ�� x
Status ListDelete4(LinkList first, int i); //13��ɾ���� i ��Ԫ��
LinkList createListF4(void);               //14��ͷ�巨������ͷ��㵥����������Ԫ�ز��뵽ͷ���������û��������ݵ��෴˳��洢
LinkList createListR4(void);               //15��β�巨������ͷ��㵥����������Ԫ�ز��뵽β���������û��������ݵ�˳��洢

//5����̬��������������13��
int Malloc5(SLinkList space);              //1�����侲̬������
void Free5(SLinkList space, int k);        //2�����ս��k
void InitList5(SLinkList L);               //3����ʼ����̬����L
void ClearList5(SLinkList L);              //4����վ�̬����L
Status ListEmpty5(SLinkList L);            //5���жϾ�̬����L�Ƿ�Ϊ��
int ListLength5(SLinkList L);              //6����̬����L�ĳ���
Status GetElem5(SLinkList L, int i, ElemType& e);  //7����ȡ��̬����L�е�i��Ԫ��
int LocateElem5(SLinkList L, ElemType e);  //8������ֵΪe��Ԫ�أ�������λ��
Status NextElem5(SLinkList L, ElemType cur_e, ElemType& next_e);   //9������ֵΪcur_e��Ԫ�أ���������ֱ�Ӻ��
Status PriorElem5(SLinkList L, ElemType cur_e, ElemType& pre_e);   //10������ֵΪcur_e��Ԫ�أ���������ֱ��ǰ��
Status ListInsert5(SLinkList L, int i, ElemType e);   //11���ھ�̬����L�е�i��Ԫ��ǰ����Ԫ��e
Status ListDelete5(SLinkList L, int i, ElemType& e);  //12���ھ�̬����L��ɾ����i��Ԫ��
void ListTraverse5(SLinkList L, void(*visit)(ElemType)); //13��������̬����L�е�Ԫ�أ�visitΪ����ָ�룬ָ���ӡ����

//6����ͷ����ʹ��βָ��ĵ�ѭ����������������12��
void InitList6(LinkList& L);            //1����ʼ����ͷ����ʹ��βָ��ĵ�ѭ������L
void DestroyList6(LinkList& L);         //2�����ٴ�ͷ����ʹ��βָ��ĵ�ѭ������
void ClearList6(LinkList& L);           //3����մ�ͷ����ʹ��βָ��ĵ�ѭ������
Status ListEmpty6(LinkList L);          //4���жϴ�ͷ����ʹ��βָ��ĵ�ѭ�������Ƿ�Ϊ��
int ListLength6(LinkList L);            //5�����ͷ����ʹ��βָ��ĵ�ѭ������ĳ���
Status GetElem6(LinkList L, int i, ElemType& e);   //6����ȡ��i��Ԫ��
int LocateElem6(LinkList L, ElemType e);           //7������ֵΪe��Ԫ�أ�����λ�����
Status NextElem6(LinkList L, ElemType cur_e, ElemType& next_e);  //8������ֵΪcur_e��Ԫ�أ�������ֱ�Ӻ��
Status PriorElem6(LinkList L, ElemType cur_e, ElemType& pre_e);  //9������ֵΪcur_e��Ԫ�أ�������ֱ��ǰ��
Status ListInsert6(LinkList& L, int i, ElemType e);              //10���ڴ�ͷ����ʹ��βָ��ĵ�ѭ������L�е�i��Ԫ��ǰ����Ԫ��e
Status ListDelete6(LinkList& L, int i, ElemType& e);             //11���ڴ�ͷ����ʹ��βָ��ĵ�ѭ������L��ɾ����i��Ԫ��
void ListTraverse6(LinkList L, void(*visit)(ElemType));          //12��������ͷ����ʹ��βָ��ĵ�ѭ������L�е�Ԫ�أ�visitΪ����ָ�룬ָ���ӡ����

//7����ͷ����˫����������������8��
void InitList7(DuLinkList& L);        //1����ʼ����ͷ����˫������L
void DestroyList7(DuLinkList& L);     //2�����ٴ�ͷ����˫������
void ClearList7(DuLinkList& L);       //3����մ�ͷ����˫������
int ListLength7(DuLinkList L);        //4�����ͷ����˫������ĳ���
DuLinkList GetElemP7(DuLinkList L, int i);               //5����ȡ��i��Ԫ�أ�����ָ��
Status ListInsertF7(DuLinkList L, int i, ElemType e);   //6���ڵ� i ��Ԫ�ؽ��ǰ����Ԫ�� e
Status ListInsertR7(DuLinkList L, int i, ElemType e);   //7���ڵ� i ��Ԫ�ؽ������Ԫ�� e
Status ListDelete7(DuLinkList L, int i, ElemType& e);   //8���ڴ�ͷ����˫������L��ɾ���� i ��Ԫ��

//8����ͷ����˫��ѭ����������������15��
void InitList8(DuLinkList& L);        //1����ʼ����ͷ����˫��ѭ������L
void DestroyList8(DuLinkList& L);     //2�����ٴ�ͷ����˫��ѭ������
void ClearList8(DuLinkList L);        //3����մ�ͷ����˫��ѭ������
Status ListEmpty8(DuLinkList L);      //4���жϴ�ͷ����˫��ѭ�������Ƿ�Ϊ��
int ListLength8(DuLinkList L);        //5�����ͷ����˫��ѭ������ĳ���
Status GetElem8(DuLinkList L, int i, ElemType& e);    //6����ȡ��i��Ԫ��
int LocateElem8(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType));  //7������ֵΪe��Ԫ�أ�����λ�����
Status NextElem8(DuLinkList L, ElemType cur_e, ElemType& next_e);                 //8������ֵΪcur_e��Ԫ�أ�������ֱ�Ӻ��
Status PriorElem8(DuLinkList L, ElemType cur_e, ElemType& pre_e);                 //9������ֵΪcur_e��Ԫ�أ�������ֱ��ǰ��
DuLinkList GetElemP8(DuLinkList L, int i);                      //10����ȡ��i��Ԫ�أ�����ָ��
Status ListInsertF8(DuLinkList L, int i, ElemType e);           //11���ڵ� i ��Ԫ�ؽ��ǰ����Ԫ�� e
Status ListInsertR8(DuLinkList L, int i, ElemType e);           //12���ڵ� i ��Ԫ�ؽ������Ԫ�� e
Status ListDelete8(DuLinkList L, int i, ElemType& e);           //13���ڴ�ͷ����˫��ѭ������L��ɾ���� i ��Ԫ��
void ListTraverse8(DuLinkList L, void(*visit)(ElemType));       //14�����������ͷ����˫��ѭ������L�е�Ԫ�أ�visitΪ����ָ�룬ָ���ӡ����
void ListTraverseBack8(DuLinkList L, void(*visit)(ElemType));   //15�����������ͷ����˫��ѭ������L�е�Ԫ�أ�visitΪ����ָ�룬ָ���ӡ����



Status compare (ElemType a, ElemType b);
//---------------------------��������Ϊ��ӡ��������---------------------------
void visit(ElemType e);
void printList1(SeqList L);        //1����ӡ��̬�洢˳���
void printList2(SqList L);         //2����ӡ��̬�洢˳���
void printList3(LinkList first);   //3����ӡ����ͷ��㵥����
void printList4(LinkList first);   //4����ӡ��ͷ��㵥����
                                   //5����ӡ��̬��������ListTraverse5������ʵ�֣����Ϸ�����
                                   //6����ӡ��ͷ����ʹ��βָ��ĵ�ѭ����������ListTraverse6������ʵ�֣����Ϸ�����
void printList7(DuLinkList L);     //7����ӡ��ͷ����˫������
                                   //8����ӡ��ͷ����˫��ѭ����������ListTraverse8������ʵ�֣����Ϸ�����
#endif
