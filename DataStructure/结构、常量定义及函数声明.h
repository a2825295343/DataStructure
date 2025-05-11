﻿#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>  //标准头文件，提供宏va_start，va_arg和va_end用于存取可变长参数表

//下面这俩常量主要指函数执行状态是否成功
#define OK 1
#define ERROR 0

//下面这俩常量主要指逻辑值，即判断“是”和“否”
#define TRUE 1
#define FALSE 0

typedef int ElemType;   //线性表数据类型，可修改
typedef int SElemType;  //栈数据类型，可修改
typedef int QElemType;  //队列数据类型，可修改
typedef int Status;     //状态返回值类型，可修改，与常量ERROR、OK、TRUE、FALSE绑定

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
} SqList;   //注意没有字母e

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

//8.5、顺序栈结构定义（静态分配，该种定义方式不常用，就不写函数了）
#define maxSize 100
typedef struct {
    SElemType elem[maxSize];   //定长数组
    int top;        //栈顶下标
} SeqStack;

//9、顺序栈结构定义（动态分配）
#define STACK_INIT_SIZE 100   //存储空间初始分配量
#define STACKINCREMENT  10    //存储空间分配的增量
typedef struct {
    SElemType* base; //栈底指针
    SElemType* top;//栈顶指针
    int StackSize;   //当前已分配的存储空间
} SqStack;   //注意没有字母e

//10、链栈结构定义
typedef struct StackNode {
    SElemType data; //节点
    struct StackNode* next; //链指针，指向的不是后继，而是前驱
} *Link;

typedef struct {
    Link top; //栈顶指针
} LinkStack;

//11、循环队列结构定义
#define MAXSIZE 100     //最大长度
typedef struct {
    QElemType* data; //初始化的动态分配存储空间
    int front; //头指针，指示队头位置 
    int rear; //尾指针，指示队尾位置 
} SqQueue;

//12、链式队列结构定义
typedef struct QNode {	 //链队结点
    QElemType data; 	//结点数据
    struct QNode* next;	//结点链指针
} QNode, *QueuePtr;

typedef struct {        //链队结构
    QueuePtr  front;	//队头指针
    QueuePtr  rear;	 	//队尾指针
} LinkQueue;

//13、数组结构定义
# define MAX_ARRAY_DIM 8  //数组维数的最大值
typedef  struct {
    ElemType* base; //数组元素基址，由InitArray 分配
    int  dim;  //数组维数
    int* bounds; //数组维界基址，由InitArray分配
    int* constants; //数组映像函数常量基址，由InitArray分配
}Array;

//14、稀疏矩阵的三元组存储结构定义
#define MaxSize 100              //非零元个数的最大值
typedef struct
{
    int i, j;               // 行下标,列下标 
    ElemType e; // 非零元素值 
}Triple;

typedef struct
{
    Triple data[MaxSize + 1]; //非零元三元组表,data[0]未用
    int mu, nu, tu; // 矩阵的行数、列数和非零元个数 
}TSMatrix;

//14.5、稀疏矩阵的行逻辑链接顺序表存储结构定义
#define maxSIZE 100
#define MAXRC 80
typedef struct {
    Triple data[maxSIZE + 1];
    int rpos[MAXRC + 1]; // 各行第一个非零元的位置表
    int mu, nu, tu; 	// 矩阵的行数、列数和非零元个数
} RLSMatrix;

//15、稀疏矩阵的十字链表存储结构定义
typedef struct OLNode                 //结点的定义
{
    int i, j;                                            // 非零元的行和列下标 
    ElemType e;                                // 非零元素值 
    struct OLNode* right, * down;    // 该非零元所在行表和
    //列表的后继链域 
}OLNode, *OLink;

typedef struct                           //链表的定义
{
    OLink* rhead, * chead;  // 行和列链表头指针向量基址,由           
    //CreatSMatrix_OL()分配
    int mu, nu, tu;            // 稀疏矩阵的行、列数和非零元个数 
}CrossList;

typedef int AtomType; //原子结点的数据域类型

//16、广义表的头尾链表存储结构定义
typedef enum { ATOM, LIST } ElemTag; // 0:原子, 1:子表
typedef struct GLNode {
ElemTag tag; // 公共部分，标志域，用于区分原子结点和表结点
union {           // 原子结点和表结点的联合部分
    AtomType atom; // 原子结点的数据域
    struct { struct GLNode* hp, * tp; } ptr;
    // ptr是表结点的指针域， ptr.hp和ptr.tp分别指向表头和表尾
};
} *GList; //广义表类型

//16.5、广义表的扩展线性链表存储结构定义，为了和上面的变量区分，变量类型和名字后加了1
typedef enum { ATOM1, LIST1 } ElemTag1; // 0:原子, 1:子表
typedef struct GLNode1 {
ElemTag1 tag1; // 公共部分，标志域，用于区分原子结点和表结点
union { // 原子结点和表结点的联合部分
    AtomType atom1; // 原子结点的值域
    struct GLNode1* hp1; // 表结点的表头指针
};
struct GLNode1* tp1; //相当于线性链表的next，指向下一个元素结点
} *GList1; //广义表类型

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

//9、顺序栈函数声明，共9个
Status InitStack9(SqStack& S);               //1、初始化顺序栈S
Status DestroyStack9(SqStack& S);            //2、销毁顺序栈S
Status ClearStack9(SqStack S);               //3、清空顺序栈S
Status StackEmpty9(SqStack& S);              //4、判断顺序栈S是否为空
Status StackFull9(SqStack& S);               //5、判断顺序栈S是否已满
int StackLength9(SqStack S);                 //6、求顺序栈S的长度
Status GetTop9(SqStack S, SElemType& e);     //7、获取栈顶元素
Status Push9(SqStack& S, SElemType e);       //8、入栈
Status Pop9(SqStack& S, SElemType& e);       //9、出栈

//10、链栈函数声明，共5个
Status InitStack10(LinkStack& S);            //1、初始化链栈S
Status StackEmpty10(LinkStack S);            //2、判断链栈S是否为空
Status GetTop10(LinkStack S, SElemType& e);  //3、获取栈顶元素
Status Push10(LinkStack& S, SElemType e);    //4、入栈
Status Pop10(LinkStack& S, SElemType& e);    //5、出栈

//11、循环队列函数声明，共7个
Status InitQueue11(SqQueue& Q);               //1、初始化循环队列Q
int QueueLength11(SqQueue Q);		          //2、求循环队列Q的长度
int QueueEmpty11(SqQueue& Q);                 //3、判断循环队列Q是否为空
int QueueFull11(SqQueue& Q);	              //4、判断循环队列Q是否已满
Status EnQueue11(SqQueue& Q, QElemType e);    //5、入队
Status DeQueue11(SqQueue& Q, QElemType& e);   //6、出队
Status GetFront11(SqQueue& Q, QElemType& e);  //7、获取队头元素

//12、链式队列函数声明，共6个
Status InitQueue12(LinkQueue& Q);		      //1、初始化链式队列Q
Status DestroyQueue12(LinkQueue& Q);	      //2、销毁链式队列Q
int isEmpty12(LinkQueue Q);		              //3、判断链式队列Q是否为空
int GetFront12(LinkQueue Q, QElemType& e);    //4、获取队头元素
Status EnQueue12(LinkQueue& Q, QElemType e);  //5、入队
Status DeQueue12(LinkQueue& Q, QElemType& e); //6、出队

//13、数组函数声明，共5个
Status InitArray13(Array& A, int dim, ...);       //1、初始化数组A
Status DestroyArray13(Array& A);                  //2、销毁数组A
Status Locate13(Array A, va_list ap, int& off);   //3、求元素在数组中相对地址
Status Value13(Array A, ElemType& e,...);         //4、A的元素值赋给变量e
Status Assign13(Array& A, ElemType e,...);        //5、变量e的值赋给所指定的A的元素

//14、稀疏矩阵的三元组存储函数声明，共2个
Status TransposeSMatrix14(TSMatrix M, TSMatrix& T);    //1、矩阵转置
void FastTransposeSMatrix14(TSMatrix M, TSMatrix& T);  //2、快速转置

//15、稀疏矩阵的十字链表存储函数声明，共1个
Status CreateSMatrix_OL15(CrossList& M);               //1、创建十字链表

//16、广义表的头尾链表存储函数声明，共3个
int GListDepth16(GList L);          //1、求广义表L的深度
int GListLength16(GList L);         //2、求广义表L的长度
int LengthRecur16(GLNode* GL);      //3、求广义表L的长度（递归版）

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
void printStack9(SqStack S);       //9、打印顺序栈
void printStack10(LinkStack S);    //10、打印链栈
void printQueue11(SqQueue Q);      //11、打印循环队列
void printQueue12(LinkQueue Q);    //12、打印链式队列
void printArray13(Array A);        //13、打印数组
void printMatrix14(TSMatrix M);    //14、打印稀疏矩阵的三元组存储结构
void printMatrix15(CrossList M);   //15、打印稀疏矩阵的十字链表存储结构
void printGList16(GList L);        //16、打印广义表的头尾链表存储结构
#endif
