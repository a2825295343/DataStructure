#include "结构、常量定义及函数声明.h"

//1、初始化表L为空表
void InitList8(DuLinkList& L)  //初始化
{
    L = (DuLinkList)malloc(sizeof(DuLNode));
    if (L)
        L->next = L->prior = L;
    else
        exit(OVERFLOW);
}

//2、销毁链表L
void DestroyList8(DuLinkList& L)
{ // 销毁
    ClearList8(L);
    free(L);
    L = NULL;
}

//3、清空链表L
void ClearList8(DuLinkList L) //清空
{
    DuLinkList p = L->next;
    while (p != L)
    {
        p = p->next;
        free(p->prior);
    }
    L->next = L->prior = L;
}

//4、判断链表L是否为空
Status ListEmpty8(DuLinkList L)
{
    if (L->next == L && L->prior == L)
        return TRUE;
    else
        return FALSE;
}

//5、求链表L的长度
int ListLength8(DuLinkList L)
{  //求长度
    int i = 0;
    DuLinkList p = L->next;
    while (p != L)
    {
        i++;
        p = p->next;
    }
    return i;
}

//6、获取链表L中第i个元素，赋值给e
Status GetElem8(DuLinkList L, int i, ElemType& e)
{  //取第i结点的值
    int j = 1;
    DuLinkList p = L->next;
    while (p != L && j < i)
    {
        j++;
        p = p->next;
    }
    if (p == L || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

//7、返回元素e的位置 
int LocateElem8(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ // 返回元素e的位置 

    int i = 0;
    DuLinkList p = L->next;
    while (p != L)
    {
        i++;
        if (compare(p->data, e))
            return i;
        p = p->next;
    }
    return 0;
}

//8、取cur_e的直接后继
Status NextElem8(DuLinkList L, ElemType cur_e, ElemType& next_e)
{//取后继
    DuLinkList p = L->next->next;
    while (p != L)
    {
        if (p->prior->data == cur_e)
        {
            next_e = p->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

//9、取cur_e的直接前驱
Status PriorElem8(DuLinkList L, ElemType cur_e, ElemType& pre_e)
{   //取前驱
    DuLinkList p = L->next->next;
    while (p != L)
    {
        if (p->data == cur_e)
        {
            pre_e = p->prior->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

//10、取第i结点地址
DuLinkList GetElemP8(DuLinkList L, int i)
{   //  /取第i结点地址
    int j;
    DuLinkList p = L;
    if (i<0 || i>ListLength8(L))
        return NULL;
    for (j = 1; j <= i; j++)
        p = p->next;
    return p;
}

//11、在第 i 个元素结点前插入元素 e
Status ListInsertF8(DuLinkList L, int i, ElemType e) {
    //在带头节点的单链表first中第 i 个元素结点前插入元素 e，成功返回OK否则返回ERROR
    DuLNode* p = L;   int k = 0;
    while (p && k < i - 1)
    {
        p = p->next;  k++;
    }                                               //寻找第 i-1个结点 
    if (!p || i < 1) {
        //printf("无效的插入位置!\n");                      //终止插入
        return ERROR;
    }                                                 //参数i值不合理返回ERROR
    DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));       //创建新结点
    newnode->data = e;
    newnode->next = p->next;                           //插入新结点
    p->next = newnode;
    newnode->prior = p;
    newnode->next->prior = newnode;
    return OK;
}

//12、在第 i 个元素结点后插入元素 e
Status ListInsertR8(DuLinkList L, int i, ElemType e)
{ //在第i后插入结点e
    DuLinkList p, s;
    if (i<1 || i>ListLength8(L) + 1)
        return ERROR;
    p = GetElemP8(L, i);
    if (!p)
        return ERROR;
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (!s)
        return ERROR;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return OK;
}

//13、删除第 i 个元素
Status ListDelete8(DuLinkList L, int i, ElemType& e)
{ //删除第i结点
    DuLinkList p;
    if (i < 1)
        return ERROR;
    p = GetElemP8(L, i);
    if (!p)
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

//14、从头遍历链表L中的元素
void ListTraverse8(DuLinkList L, void(*visit)(ElemType))
{     //从头指针开始往后遍历
    DuLinkList p = L->next;
    while (p != L)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

//15、从尾遍历链表L中的元素
void ListTraverseBack8(DuLinkList L, void(*visit)(ElemType))
{ //从尾指针开始往前遍历
    DuLinkList p = L->prior;
    while (p != L)
    {
        visit(p->data);
        p = p->prior;
    }
    printf("\n");
}
