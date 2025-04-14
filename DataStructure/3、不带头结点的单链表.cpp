#include "结构、常量定义及函数声明.h"

//1、初始化单链表first为空表
void InitList3(LinkList& first) {  //初始化单链表first为空表
    first = NULL;
}

//2、销毁单链表
void DestroyList3(LinkList& first) {
    //删去单链表first的所有结点
    LNode* q;
    while (first) {
        //当链不空时，循环逐个删去所有结点
        q = first; first = first->next;
        free(q);        //释放 
    }
}

//3、清空单链表
void clear3(LinkList& first) {
    //删去单链表first中所有结点
    LNode* q;
    while (first) {
        //当链不空时，循环逐个删去所有结点
        q = first; first = first->next;
        free(q);        //释放 
    }
}

//4、判断链表是否为空
int ListEmpty3(LinkList first)
{                        //若单链表first为空返回1,否则返回0
    return !first;
}

//5、求链表的长度
int ListLength3(LinkList first)   //函数值为单链表first长度
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

//6、获取链表中第i个元素，返回第i个元素值
ElemType GetElem3(LinkList first, int i)
{    //函数返回单链表first中第i个元素值，不存在返回NULL
    LinkList p;        int j;
    p = first; j = 1;
    while (p && (j < i)) {           //找第i个元素
        p = p->next; ++j;
    }
    if (!p || j > i) return NULL;  //第i个元素不存在,p 空没找到
    //j>i  是输入i<1的情况
    return p->data;
}

//7、搜索数据值为x的结点，成功返回x第一次出现的位置，否则返回NULL
LinkList LocateElem3(LinkList first, ElemType x) {//在单链表first中
    //搜索数据值为x的结点，成功返回x第一次出现的位置，否则返回NULL
    LNode* p = first;                //指针 p 指示第一个结点
    while (p && (p->data != x))
        p = p->next;
    return p;
}

//8、判断x是否在单链表中
int IsIn3(LinkList first, ElemType x)
{                             //若x在单链表first中函数返回1否则返回0
    LNode* p = first;                       //指针 p 指示第一个结点
    while (p && (p->data != x))        //找x
        p = p->next;
    return !(p == NULL);
}

//9、求x的直接后继，返回指针
LinkList NextElem3(LinkList first, ElemType x) { //函数返回单链表//first中值为x结点的直接后继结点地址，没有返回NULL
    LinkList p = first;
    while (p && p->data != x)                  //找x
        p = p->next;
    if (!p || !p->next) return NULL;            //没有直接后继 
    return  p->next;
}

//10、求x的直接前驱，返回指针
LinkList PriorElem3(LinkList first, ElemType x)
{          //函数返回x的直接前驱的结点地址，没有返回NULL
    LinkList  p = first;
    while (p && p->next && (p->next->data != x))  //找x，只要x在
        //p→next→data，那么其前驱就是p
        p = p->next;
    if (!p || !p->next) return NULL;                  //没有直接前驱 
    return  p;
}

//11、在第 i 个元素结点前插入元素 x
int ListInsert3(LinkList& first, int i, ElemType x) {
    //在单链表first中第 i 个元素结点前插入元素 x，成功返回1否则返回0
    LNode* newnode = (LNode*)malloc(sizeof(LNode));
    newnode->data = x;                                  //创建新结点
    if (i == 1) {                                     //插入为第一个结点
        newnode->next = first;                //新结点成为第一个结点
        first = newnode;
        return OK;
    }
    LNode* p = first;   int k = 1;           //插入位置不是第一个结点
        while (p && k < i - 1)
        {
            p = p->next;  k++;
        }   //移动指针，找第 i-1个结点 
        if (!p || i < 1)  {
            printf("无效的插入位置!\n");                //终止插入
            free(newnode);
            return ERROR;
     }
     newnode->next = p->next;
     p->next = newnode;                           //插在表中间或末尾
     return OK;
    }

//12、删除第 i 个元素，成功返回OK否则返回ERROR
int ListDelete3(LinkList& first, int i) {
    LNode* q;
    //在单链表first中删除第 i 个结点，删除成功返回1否则返回0
    if (first && i == 1)                        //删除表中第 1 个结点
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
            //找不到第i-1个结点
            printf("无效的删除位置!\n");
            return ERROR;
        }
        else {
            q = p->next;            //删除中间结点或尾结点元素         
            p->next = q->next;
        }
    }
     free(q);
     return OK;                   //释放q
}

//打印单链表first
void printList3(LinkList first) {
	LNode* p = first;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}