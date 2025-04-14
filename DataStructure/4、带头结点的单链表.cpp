#include "结构、常量定义及函数声明.h"

//1、初始化
void InitList4(LinkList &first) {
    //初始化带头结点的单链表first为空表
    first = (LNode*)malloc(sizeof(LNode));   //创建头结点 
    first->next = NULL;
}

//2、销毁
void  DestroyList4(LinkList& first) {
    //删去带头节点单链表first中的所有结点，包括头结点
    LNode* q;
    while (first) {
        //当链不空时，循环逐个删去所有结点
        q = first;
        first = first->next;
        free(q);        //释放 
    }
}

//3、清空
void clear4(LinkList& first) {      // 将表重置为空表 
    //删去带头结点单链表first中的所有结点，保留头结点
    LNode* p, * q = first->next;
    while (q) {                   //当链不空时，循环逐个删去所有结点
        p = q; q = q->next;
        free(p);                   //释放 
    };
    first->next = NULL;      //头结点指针域为空 
}

//4、判断链表是否为空
int  ListEmpty4(LinkList first)
{                        //若带头结点单链表first为空返回1,否则返回0
    return  !(first->next);
}

//5、求链表的长度
int ListLength4(LinkList first) //函数返回带头结点单链表first长度
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

//6、获取链表中第i个元素
ElemType GetElem4(LinkList first, int i) {
    //函数返回带头结点单链表first第i个元素值，不存在返回NULL
    LinkList p;        
    int j;
    p = first->next;  j = 1;
    while (p && (j < i)) {                            //找第i个元素
        p = p->next; ++j;
    }
    if (!p || j > i) return NULL;                   //第i个元素不存在
    return p->data;
}

//7、查找值为x的元素，返回指针
LNode* LocateElem4(LinkList first, ElemType x) { //在带头结点单//链表first中搜索其值为x的结点，查找成功返回x位置，否则返回NULL
    LNode* p = first->next;                //指针 p 指示第一个结点
    while (p && (p->data != x))
        p = p->next;
    return p;
}

//8、在带头结点单链表中查找值为x的元素，返回位置序号
int LocateELem_L4(LinkList first, ElemType x) {
    //返回L中值为e的数据元素的位置序号，查找失败返回0 
    LNode* p = first->next; int j = 1;
    while (p && p->data != x)
    {
        p = p->next;  j++;
    }
    if (p) return j;
    else return 0;
}

//9、若x在带头结点单链表first中函数返回1否则返回0
int IsIn4(LinkList first, ElemType x)
{                  //若x在带头结点单链表first中函数返回1否则返回0
    LNode* p = first->next;                       //指针 p 指示第一个结点
    while (p && (p->data != x))
        p = p->next;
    return !(p == NULL);
}

//10、带头结点单链表first中x的直接后继的结点地址，没有返回NULL
LinkList NextElem4(LinkList first, ElemType x) { //函数返回带头结点单链表first中x的直接后继的结点地址，没有返回NULL
    LinkList p = first->next;
    while (p && p->data != x)                            //找x
        p = p->next;
    if (!p || !p->next) return NULL;            //没有直接后继 
    return  p->next;
}

//11、带头结点单链表first中x的直接前驱的结点地址，没有返回NULL
LinkList PriorElem4(LinkList first, ElemType x) { //函数返回带头结点单链表first中x的直接前驱的结点地址，没有返回NULL
    LinkList  p = first->next;
    while (p && p->next && (p->next->data != x))                    //找x
        p = p->next;
    if (!p || !p->next) return NULL;                          //没有直接前驱 
    return  p;
}

//12、在第 i 个元素结点前插入元素 x
int ListInsert4(LinkList first, int i, ElemType x) {
    //在带头节点的单链表first中第 i 个元素结点前插入元素 x，成功返回OK否则返回ERROR
    LNode* p = first;   int k = 0;
    while (p && k < i - 1)
    {
        p = p->next;  k++;
    }                                               //寻找第 i-1个结点 
    if (!p || i < 1)  {
        //printf("无效的插入位置!\n");                      //终止插入
        return ERROR;
    }                                                 //参数i值不合理返回ERROR
    LNode* newnode = (LNode*)malloc(sizeof(LNode));       //创建新结点
    newnode->data = x;
    newnode->next = p->next;                                   //插入新结点
    p->next = newnode;
    return OK;
}

//13、删第 i 个元素，成功返回OK否则返回ERROR
int ListDelete4(LinkList first, int i) {
    //删除带头节点单链表first的第 i 个元素，成功返回OK否则返回ERROR
    LinkList q;
        LNode* p = first; int k = 0;
    while (p && k++ < i - 1)  p = p->next;   //寻找第i-1个结点
    if (!p || !(p->next) || i < 1)
        return ERROR;                 //i值不合理(比如0或小于0的数)或空表	
    q = p->next;
    p->next = q->next; //删除结点
    free(q);  //释放
    return OK;
}

//14、创建带头结点单链表，用户输入数据，从第一个开始往后加,每个数据之间用空格隔开，回车结束
LinkList createListF4(void) {
    //创建带头结点单链表，函数返回
    LNode* first = (LinkList)malloc(sizeof(LNode)); //单链表的头指针
    LNode* r = first;                               //建立表头结点，r 指向表尾
    char ch;
    while ((ch = getchar()) != '\n') {
        LNode* q = (LNode*)malloc(sizeof(LNode));
        q->data = ch;                             //建立新结点
        r->next = q;   r = q;                     //插入到表末端
    }
    r->next = NULL;
    return first;
}

//15、创建带头结点单链表，用户输入数据，从最后一个开始往前加,每个数据之间用空格隔开，回车结束
LinkList createListR4(void) {//创建带头结点单链表，函数返回
    //单链表的头指针
    LNode* first = (LinkList)malloc(sizeof(LNode)); //建立表头结点
    first->next = NULL;
    char ch;
    while (( ch = getchar()) != '\n') {
        LNode* q = (LNode*)malloc(sizeof(LNode));
        q->data = ch;                          //建立新结点
        q->next = first->next;                    //插入到表前端
        first->next = q;
    }
    return first;
}

//打印带头结点单链表first
void printList4(LinkList first) {
	LNode* p = first->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}