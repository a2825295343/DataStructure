#include "结构、常量定义及函数声明.h"

//1、初始化表L为空表
void InitList1(SeqList& L)
{                                 
    L.length = 0;
}

//2、回收线性表L
void DestroyList1(SeqList& L)
{
    L.length = 0;
}

//3、清空线性表L
void ClearList1(SeqList& L)         
{
    L.length = 0;
}

//4、若线性表L为空返回1,否则返回0
int  ListEmpty1(SeqList L) { 
    return(!(L.length));
}

//5、函数值是表L的长度
int ListLength1(SeqList L)
{                                                       
    return(L.length);
}

//6、获取表L中第 i 个元素
ElemType GetElem1(SeqList L, int i) { 
    if (1 <= i && i <= L.length)
        return (L.data[i - 1]); //第i-1的单元存储着第i个数据
    else  return NULL;
}

//7、在线性表L中查找值为e的数据元素，返回其位序
int LocateELem1(SeqList L, ElemType e)
{                                                  
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e) return i + 1;
    return ERROR;
}

//8、判断x是否在表L中
int IsIn1(SeqList L, ElemType x) {  
    //x在L中返回OK，否则返回ERROR
    int  i = 0, found = ERROR;
    while ((i < L.length) && !found)
        if (L.data[i] != x) i++;
        else found = OK;
    return found;
}

//9、求表L中元素x的直接后继
int NextElem1(SeqList L, ElemType x) { //如果x在表L中且
    //有直接后继，函数值返回其直接后继的位置，否则返回-1
    int i = 0;
    while ((i < L.length) && (L.data[i] != x)) i++;    //查找x
    if ((0 <= i) && (i < L.length - 1)) return i + 1;
    else return ERROR;
}

//10、求表L中元素x的直接前驱
int PriorElem1(SeqList L, ElemType x) {   //如果x在表L中且
    //有直接前驱，函数值返回其直接前驱的位置，否则返回-1
    int i = 0;
    while (i < L.length && L.data[i] != x) i++;          //查找x 
    if ((0 < i) && (i < L.length)) return i - 1;     //返回位置 
    else return ERROR;
}

//11、在顺序表L中第 i 个元素前插入 x,插入成功返回OK，不成功 返回ERROR
int ListInsert1(SeqList& L, int i, ElemType x) {  //在顺序表L中
    //第 i 个元素前插入 x,插入成功返回OK，不成功 返回ERROR
    if ((i < 1) || (i > L.length + 1) || (L.length == ListSize))
        return ERROR;                           //插入不成功	
    else {
        for (int j = L.length; j > i - 1; j--)                //后移
            L.data[j] = L.data[j - 1];
        L.data[i - 1] = x;   L.length++;  return OK;     //插入成功       
    }
}

//12、在顺序表L中删除第 i 个元素,成功返回OK，否则返回ERROR
int ListDelete1(SeqList& L, int  i) {//在顺序表L中删除第i个元素,
    //成功返回OK，否则返回ERROR
    if ((i < 1) || (i > L.length)) return ERROR;
    L.length--;
    for (int j = i - 1; j < L.length + 1; j++)        //前移
        L.data[j] = L.data[j + 1];
    return OK;                                           //成功删除	
}

//打印线性表L
void printList1(SeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}