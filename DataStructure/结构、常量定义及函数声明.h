#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ERROR 0
#define OK 1
typedef int ElemType;   //数据类型，可修改
typedef int Status;   //状态返回值类型，可修改，与常量ERROR、OK绑定

//1、静态存储顺序表结构定义
#define ListSize 100    //最大允许长度
typedef struct {
    ElemType data[ListSize];    //存储空间
    int length;         //当前元素个数
} SeqList;

//2、动态存储顺序表结构定义
#define LIST_INIT_SIZE 12
#define LISTINCREMENT 4
typedef struct {
    ElemType* data;
    int length;
    int listsize;
} SqList;

//3-4及6、单链表结构定义
typedef struct LNode {
    ElemType   data;       //数据域
    struct LNode* next;   //指针域
}LNode, *LinkList;

//5、静态链表结构定义
#define MAX_SIZE 100 
typedef struct
{
    ElemType data; // 数据域   
    int cur; // 游标域 
}component, SLinkList[MAX_SIZE];

//7-8、双向链表结构定义
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode* prior, * next;
}DuLNode, *DuLinkList;


//---------------------------以下内容为算法函数声明---------------------------

//1、静态存储顺序表函数声明，共12个
void InitList1(SeqList& L);               //1、初始化表L为空表
void DestroyList1(SeqList& L);            //2、销毁线性表L
void ClearList1(SeqList& L);              //3、清空线性表L
int ListEmpty1(SeqList L);                //4、判断线性表L是否为空
int ListLength1(SeqList L);               //5、求线性表L的长度
ElemType GetElem1(SeqList L, int i);      //6、获取表L中第 i 个元素
int LocateELem1(SeqList L, ElemType e);   //7、查找值为e的元素，返回其位序
int IsIn1(SeqList L, ElemType x);         //8、判断x是否在表L中
int NextElem1(SeqList L, ElemType x);     //9、求x的直接后继
int PriorElem1(SeqList L, ElemType x);    //10、求x的直接前驱
Status ListInsert1(SeqList& L, int i, ElemType e); //11、在第 i 个元素前插入元素 e
Status ListDelete1(SeqList& L, int i);    //12、在顺序表L中删除第 i 个元素

//2、动态存储顺序表函数声明，共14个
Status InitList2(SqList& L);              //1、初始化表L为空表
Status DestroyList2(SqList& L);           //2、销毁线性表L
Status ClearList2(SqList& L);             //3、清空线性表L
int ListEmpty2(SqList L);                 //4、判断线性表L是否为空
int ListLength2(SqList L);                //5、求线性表L的长度
ElemType GetElem2(SqList L, int i);       //6、获取表L中第 i 个元素
int LocateElem2(SqList L, ElemType x);    //7、查找值为x的元素，返回其位序
int IsIn2(SqList L, ElemType x);          //8、判断x是否在表L中
int NextElem2(SqList L, ElemType x);      //9、求x的直接后继
int PriorElem2(SqList L, ElemType x);     //10、求x的直接前驱
Status ListInsert2(SqList& L, int i, ElemType e); //11、在第 i 个元素前插入元素 e
Status ListDelete2(SqList& L, int i);     //12、在顺序表L中删除第 i 个元素
void Union2(SqList& A, SqList B);         //13、集合的“并”操作
void Intersection2(SqList& A, SqList B);  //14、集合的“交”操作

//3、不带头结点的单链表函数声明，共12个
void InitList3(LinkList& first);          //1、初始化单链表first为空表
void DestroyList3(LinkList& first);       //2、销毁单链表
void clear3(LinkList& first);             //3、清空单链表
int ListEmpty3(LinkList first);           //4、判断单链表是否为空
int ListLength3(LinkList first);          //5、求单链表的长度
ElemType GetElem3(LinkList first, int i); //6、获取单链表中第i个元素
LinkList LocateElem3(LinkList first, ElemType x); //7、查找值为x的元素，返回指针
int IsIn3(LinkList first, ElemType x); //8、判断x是否在单链表中
LinkList NextElem3(LinkList first, ElemType x);   //9、求x的直接后继
LinkList PriorElem3(LinkList first, ElemType x);  //10、求x的直接前驱
Status ListInsert3(LinkList& first, int i, ElemType x); //11、在第 i 个元素前插入元素 x
Status ListDelete3(LinkList& first, int i);  //12、删除第 i 个元素

//4、带头结点的单链表函数声明，共15个
void InitList4(LinkList& first);           //1、初始化带头结点单链表first为空表
void DestroyList4(LinkList& first);        //2、销毁带头结点单链表
void clear4(LinkList& first);              //3、清空带头结点单链表
int ListEmpty4(LinkList first);            //4、判断带头结点单链表是否为空
int ListLength4(LinkList first);           //5、求带头结点单链表的长度
ElemType GetElem4(LinkList first, int i);  //6、获取带头结点单链表中第i个元素
LNode* LocateElem4(LinkList first, ElemType x);  //7、查找值为x的元素，返回指针
int LocateELem_L4(LinkList first, ElemType x);   //8、查找值为x的元素，返回位置序号
int IsIn4(LinkList first, ElemType x);    //9、判断x是否在带头结点单链表中
LinkList NextElem4(LinkList first, ElemType x);  //10、求x的直接后继
LinkList PriorElem4(LinkList first, ElemType x); //11、求x的直接前驱
Status ListInsert4(LinkList first, int i, ElemType x);  //12、在第 i 个元素前插入元素 x
Status ListDelete4(LinkList first, int i); //13、删除第 i 个元素
LinkList createListF4(void);               //14、头插法创建带头结点单链表，新增的元素插入到头部，即按用户输入数据的相反顺序存储
LinkList createListR4(void);               //15、尾插法创建带头结点单链表，新增的元素插入到尾部，即按用户输入数据的顺序存储

//5、静态链表函数声明，共13个
int Malloc5(SLinkList space);              //1、分配静态链表结点
void Free5(SLinkList space, int k);        //2、回收结点k
void InitList5(SLinkList L);               //3、初始化静态链表L
void ClearList5(SLinkList L);              //4、清空静态链表L
Status ListEmpty5(SLinkList L);            //5、判断静态链表L是否为空
int ListLength5(SLinkList L);              //6、求静态链表L的长度
Status GetElem5(SLinkList L, int i, ElemType& e);  //7、获取静态链表L中第i个元素
int LocateElem5(SLinkList L, ElemType e);  //8、查找值为e的元素，返回其位序
Status NextElem5(SLinkList L, ElemType cur_e, ElemType& next_e);   //9、查找值为cur_e的元素，返回它的直接后继
Status PriorElem5(SLinkList L, ElemType cur_e, ElemType& pre_e);   //10、查找值为cur_e的元素，返回它的直接前驱
Status ListInsert5(SLinkList L, int i, ElemType e);   //11、在静态链表L中第i个元素前插入元素e
Status ListDelete5(SLinkList L, int i, ElemType& e);  //12、在静态链表L中删除第i个元素
void ListTraverse5(SLinkList L, void(*visit)(ElemType)); //13、遍历静态链表L中的元素，visit为函数指针，指向打印函数

//6、带头结点的使用尾指针的单循环链表函数声明，共12个
void InitList6(LinkList& L);            //1、初始化带头结点的使用尾指针的单循环链表L
void DestroyList6(LinkList& L);         //2、销毁带头结点的使用尾指针的单循环链表
void ClearList6(LinkList& L);           //3、清空带头结点的使用尾指针的单循环链表
Status ListEmpty6(LinkList L);          //4、判断带头结点的使用尾指针的单循环链表是否为空
int ListLength6(LinkList L);            //5、求带头结点的使用尾指针的单循环链表的长度
Status GetElem6(LinkList L, int i, ElemType& e);   //6、获取第i个元素
int LocateElem6(LinkList L, ElemType e);           //7、查找值为e的元素，返回位置序号
Status NextElem6(LinkList L, ElemType cur_e, ElemType& next_e);  //8、查找值为cur_e的元素，求它的直接后继
Status PriorElem6(LinkList L, ElemType cur_e, ElemType& pre_e);  //9、查找值为cur_e的元素，求它的直接前驱
Status ListInsert6(LinkList& L, int i, ElemType e);              //10、在带头结点的使用尾指针的单循环链表L中第i个元素前插入元素e
Status ListDelete6(LinkList& L, int i, ElemType& e);             //11、在带头结点的使用尾指针的单循环链表L中删除第i个元素
void ListTraverse6(LinkList L, void(*visit)(ElemType));          //12、遍历带头结点的使用尾指针的单循环链表L中的元素，visit为函数指针，指向打印函数

//7、带头结点的双向链表函数声明，共8个
void InitList7(DuLinkList& L);        //1、初始化带头结点的双向链表L
void DestroyList7(DuLinkList& L);     //2、销毁带头结点的双向链表
void ClearList7(DuLinkList& L);       //3、清空带头结点的双向链表
int ListLength7(DuLinkList L);        //4、求带头结点的双向链表的长度
DuLinkList GetElemP7(DuLinkList L, int i);               //5、获取第i个元素，返回指针
Status ListInsertF7(DuLinkList L, int i, ElemType e);   //6、在第 i 个元素结点前插入元素 e
Status ListInsertR7(DuLinkList L, int i, ElemType e);   //7、在第 i 个元素结点后插入元素 e
Status ListDelete7(DuLinkList L, int i, ElemType& e);   //8、在带头结点的双向链表L中删除第 i 个元素

//8、带头结点的双向循环链表函数声明，共15个
void InitList8(DuLinkList& L);        //1、初始化带头结点的双向循环链表L
void DestroyList8(DuLinkList& L);     //2、销毁带头结点的双向循环链表
void ClearList8(DuLinkList L);        //3、清空带头结点的双向循环链表
Status ListEmpty8(DuLinkList L);      //4、判断带头结点的双向循环链表是否为空
int ListLength8(DuLinkList L);        //5、求带头结点的双向循环链表的长度
Status GetElem8(DuLinkList L, int i, ElemType& e);    //6、获取第i个元素
int LocateElem8(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType));  //7、查找值为e的元素，返回位置序号
Status NextElem8(DuLinkList L, ElemType cur_e, ElemType& next_e);                 //8、查找值为cur_e的元素，求它的直接后继
Status PriorElem8(DuLinkList L, ElemType cur_e, ElemType& pre_e);                 //9、查找值为cur_e的元素，求它的直接前驱
DuLinkList GetElemP8(DuLinkList L, int i);                      //10、获取第i个元素，返回指针
Status ListInsertF8(DuLinkList L, int i, ElemType e);           //11、在第 i 个元素结点前插入元素 e
Status ListInsertR8(DuLinkList L, int i, ElemType e);           //12、在第 i 个元素结点后插入元素 e
Status ListDelete8(DuLinkList L, int i, ElemType& e);           //13、在带头结点的双向循环链表L中删除第 i 个元素
void ListTraverse8(DuLinkList L, void(*visit)(ElemType));       //14、正向遍历带头结点的双向循环链表L中的元素，visit为函数指针，指向打印函数
void ListTraverseBack8(DuLinkList L, void(*visit)(ElemType));   //15、反向遍历带头结点的双向循环链表L中的元素，visit为函数指针，指向打印函数



Status compare (ElemType a, ElemType b);
//---------------------------以下内容为打印函数声明---------------------------
void visit(ElemType e);
void printList1(SeqList L);        //1、打印静态存储顺序表
void printList2(SqList L);         //2、打印动态存储顺序表
void printList3(LinkList first);   //3、打印不带头结点单链表
void printList4(LinkList first);   //4、打印带头结点单链表
                                   //5、打印静态链表已在ListTraverse5函数中实现，在上方声明
                                   //6、打印带头结点的使用尾指针的单循环链表已在ListTraverse6函数中实现，在上方声明
void printList7(DuLinkList L);     //7、打印带头结点的双向链表
                                   //8、打印带头结点的双向循环链表已在ListTraverse8函数中实现，在上方声明
#endif
