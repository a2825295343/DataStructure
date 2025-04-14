#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ERROR 0
#define OK 1
typedef int ElemType;   //数据类型，可修改

// 1、静态存储顺序表结构定义
#define ListSize 100    //最大允许长度
typedef struct {
    ElemType data[ListSize];    //存储空间
    int length;         //当前元素个数
} SeqList;

// 2、动态存储顺序表结构定义
#define LIST_INIT_SIZE 12
#define LISTINCREMENT 4
typedef struct {
    ElemType* data;
    int length;
    int listsize;
} SqList;

//3-4、单链表结构定义
typedef struct LNode {
    ElemType   data;       //数据域
    struct LNode* next;   //指针域
}LNode, *LinkList;

//---------------------------以下内容为算法函数声明---------------------------

// 1、静态存储顺序表函数声明，共12个
void InitList1(SeqList& L);              //1、初始化表L为空表
void DestroyList1(SeqList& L);           //2、销毁线性表L
void ClearList1(SeqList& L);             //3、清空线性表L
int ListEmpty1(SeqList L);               //4、判断线性表L是否为空
int ListLength1(SeqList L);              //5、求线性表L的长度
ElemType GetElem1(SeqList L, int i);     //6、获取表L中第 i 个元素
int LocateELem1(SeqList L, ElemType e);  //7、查找值为e的元素，返回其位序
int IsIn1(SeqList L, ElemType x);        //8、判断x是否在表L中
int NextElem1(SeqList L, ElemType x);    //9、求x的直接后继
int PriorElem1(SeqList L, ElemType x);   //10、求x的直接前驱
int ListInsert1(SeqList& L, int i, ElemType e); //11、在第 i 个元素前插入元素 e
int ListDelete1(SeqList& L, int i);      //12、在顺序表L中删除第 i 个元素

// 2、动态存储顺序表函数声明，共14个
int InitList2(SqList& L);                //1、初始化表L为空表
int DestroyList2(SqList& L);             //2、销毁线性表L
int ClearList2(SqList& L);               //3、清空线性表L
int ListEmpty2(SqList L);                //4、判断线性表L是否为空
int ListLength2(SqList L);               //5、求线性表L的长度
ElemType GetElem2(SqList L, int i);      //6、获取表L中第 i 个元素
int LocateElem2(SqList L, ElemType x);   //7、查找值为x的元素，返回其位序
int IsIn2(SqList L, ElemType x);         //8、判断x是否在表L中
int NextElem2(SqList L, ElemType x);     //9、求x的直接后继
int PriorElem2(SqList L, ElemType x);    //10、求x的直接前驱
int ListInsert2(SqList& L, int i, ElemType e); //11、在第 i 个元素前插入元素 e
int ListDelete2(SqList& L, int i);       //12、在顺序表L中删除第 i 个元素
void Union2(SqList& A, SqList B);        //13、集合的“并”操作
void Intersection2(SqList& A, SqList B); //14、集合的“交”操作

// 3、不带头结点的单链表函数声明，共12个
void InitList3(LinkList& first);         //1、初始化单链表first为空表
void DestroyList3(LinkList& first);      //2、销毁单链表
void clear3(LinkList& first);            //3、清空单链表
int ListEmpty3(LinkList first);          //4、判断单链表是否为空
int ListLength3(LinkList first);         //5、求单链表的长度
ElemType GetElem3(LinkList first, int i); //6、获取单链表中第i个元素
LinkList LocateElem3(LinkList first, ElemType x); //7、查找值为x的元素，返回指针
int IsIn3(LinkList first, ElemType x); //8、判断x是否在单链表中
LinkList NextElem3(LinkList first, ElemType x);   //9、求x的直接后继
LinkList PriorElem3(LinkList first, ElemType x);  //10、求x的直接前驱
int ListInsert3(LinkList& first, int i, ElemType x); //11、在第 i 个元素前插入元素 x
int ListDelete3(LinkList& first, int i);  //12、删除第 i 个元素

// 4、带头结点的单链表函数声明，共15个
void InitList4(LinkList& first);          //1、初始化带头结点单链表first为空表
void DestroyList4(LinkList& first);       //2、销毁带头结点单链表
void clear4(LinkList& first);             //3、清空带头结点单链表
int ListEmpty4(LinkList first);           //4、判断带头结点单链表是否为空
int ListLength4(LinkList first);          //5、求带头结点单链表的长度
ElemType GetElem4(LinkList first, int i); //6、获取带头结点单链表中第i个元素
LNode* LocateElem4(LinkList first, ElemType x);  //7、查找值为x的元素，返回指针
int LocateELem_L4(LinkList first, ElemType x);   //8、查找值为x的元素，返回位置序号
int IsIn4(LinkList first, ElemType x);    //9、判断x是否在带头结点单链表中
LinkList NextElem4(LinkList first, ElemType x);  //10、求x的直接后继
LinkList PriorElem4(LinkList first, ElemType x); //11、求x的直接前驱
int ListInsert4(LinkList first, int i, ElemType x);  //12、在第 i 个元素前插入元素 x
int ListDelete4(LinkList first, int i);   //13、删除第 i 个元素
LinkList createListF4(void);              //14、创建带头结点单链表，用户输入数据，从第一个开始往后加
LinkList createListR4(void);              //15、创建带头结点单链表，用户输入数据，从最后一个开始往前加


//---------------------------以下内容为打印函数声明---------------------------

void printList1(SeqList L);        //打印静态存储顺序表
void printList2(SqList L);         //打印动态存储顺序表
void printList3(LinkList first);   //打印不带头结点单链表
void printList4(LinkList first);   //打印带头结点单链表
#endif
