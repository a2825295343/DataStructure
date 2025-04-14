//#include <stdlib.h>
#include "结构、常量定义及函数声明.h"
//#define ERROR 0         //错误标志
//#define OK 1            //成功标志
//typedef int ElemType;    //线性表数据类型
//
//#define LIST_INIT_SIZE  12	             // 线性表存储空间的初始分配量
//#define LISTINCREMENT  4		// 线性表存储空间的分配增量
//
//typedef struct
//{
//	ElemType* data;	        // 存储空间基址
//	int length;		        // 顺序表当前长度
//	int listsize;	       // 当前分配的存储容量(以sizeof(ListData)为单位)
//}SqList;
//1、初始化表L为空表
int InitList2(SqList& L)
{                                	// 分配指定大小的存储空间给顺序表
	L.data = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));   //分配存储单元
	if (!L.data)             // 存储分配失败
		return ERROR;
	L.length = 0;             // 当前长度初始化为0
	L.listsize = LIST_INIT_SIZE; // 指定分配的存储容量	
	return OK;
}

//2、回收顺序线性表L，将顺序表结构体中的所有成员销毁（空间释放， 数值置0）
int DestroyList2(SqList& L)
{                    	// 先释放空间，然后置空
	free(L.data);
	L.length = 0;
	L.listsize = 0;
	return OK;
}

//3、清空线性表L
int ClearList2(SqList& L)
{                   //清空线性表L
	L.length = 0;
	return OK;
}

//4、若线性表L为空返回1,否则返回0
int ListEmpty2(SqList L)
{
	return(!(L.length));
}

//5、求表L的长度
int  ListLength2(SqList L)
{
	// L.length记录当前顺序表的长度，直接返回
	return (L.length);
}

//6、获取表L中第 i 个元素
ElemType GetElem2(SqList L, int i) {//函数值为表L中
	//第 i 个元素
	if (1 <= i && i <= L.length)
		return (*(L.data + i - 1));
	else return NULL;
}

//7、在线性表L中查找值为x的数据元素，返回其位序
int  LocateElem2(SqList L, ElemType x) {//查找x在表   
	//L中位置, 若查找成功，返回x的位置，否则返回ERROR
	int i = 0;
	while ((i < L.length) && (*(L.data + i) != x)) i++;   //查找
	if (i < L.length) return i;                    //成功,返回位置
	else return -1;                             //失败
}

//8、判断x是否在表L中
int IsIn2(SqList L, ElemType x) {  //判断x是否在表L中
	//x在L中返回1，否则返回0
	int i = 0, found = ERROR;
	while ((i < L.length) && !found)
		if (*(L.data + i) != x) i++;
		else found = OK;
	return found;
}

//9、在表L中求x的直接后继
int  NextElem2(SqList L, ElemType x) { //如果x在表L中且
	//有直接后继，函数值返回其直接后继的位置，否则返回ERROR
	int i = 0;
	while ((i < L.length) && (*(L.data + i) != x)) i++;    //查找x
	if ((0 <= i) && (i < L.length - 1)) return i + 1;
	else return ERROR;
}

//10、在表L中求x的直接前驱
int PriorElem2(SqList L, ElemType x) {   //如果x在表L中且
	//有直接前驱，函数值返回其直接前驱的位置，否则返回-1
	int i = 0;
	while (i < L.length && *(L.data + i) != x) i++;          //查找x 
	if ((0 < i) && (i < L.length)) return i - 1;
	else return ERROR;
}

//11、在线性表L中第i个元素前插入e
int ListInsert2(SqList& L, int i, ElemType e)
{
	ElemType* newbase, * q, * p;
	if ((i < 1) || (i > L.length + 1)) return ERROR;          //输入的i不合法
	if (L.length == L.listsize)                           // 当前存储空间已满, 增加分配空间
	{           // realloc改变L.data所指内存的大小，原始所指内存中的数据不变。
		newbase = (ElemType*)realloc(L.data, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) return ERROR;                       //申请新空间失败
		L.data = newbase;                                      // 新基址
		L.listsize += LISTINCREMENT;                   // 增加存储容量
	}
	q = L.data + i - 1;                                    // 指定插入的位置
	for (p = L.data + L.length - 1; p >= q; --p)   *(p + 1) = *p;     // q之后的元素右移
	*q = e;	 ++L.length;	return OK;                         // 插入e ，表长增1 
}

//12、在顺序表L中删除第i个元素
int ListDelete2(SqList& L, int i)
{
	ElemType* p, * q;
	if (i < 1 || i > L.length)  return ERROR;          // i值不合法
	p = L.data + i - 1;			 // p为被删除元素的位置
	q = L.data + L.length - 1;	              // 表尾元素的位置
	for (++p; p <= q; ++p)			// 被删除元素之后的元素左移
		*(p - 1) = *p;
	L.length--;					// 表长减1
	return OK;
}

//13、集合的“并”操作
void Union2(SqList& A, SqList B) {
	int n = ListLength2(A);
	int m = ListLength2(B);
	for (int i = 1; i < m+1; i++) {
		ElemType x = GetElem2(B, i);  //在B中取一元素
		int k = LocateElem2(A, x);   //在A中查找它
		if (k == -1)                          //若未找到插入它
		{
			ListInsert2(A, n, x);  n++;		
		}
	}
}

//14、集合的“交”操作
void Intersection2(SqList& A, SqList B) {
	int n = ListLength2(A);
	int m = ListLength2(B);
	int i = 0;
	while (i < n) {
		int x = GetElem2(A, i);          //在A中取第i个元素
		int k = LocateElem2(B, x);        //在B中找i位置
		if (k == -1) { ListDelete2(A, i);  n--; }
		else i++;                            //未找到在A中删除它
	}
}

//打印线性表L
void printList2(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}