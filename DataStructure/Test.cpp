#include "结构、常量定义及函数声明.h"

void visit(ElemType e) { printf("%d\n", e); }

Status compare(ElemType a, ElemType b) { //比较函数，比较规则可以自定义
	return a == b;
}

int main() {
	//-------------------------1、静态存储线性表-------------------------
	SeqList L1;
    InitList1(L1);
    ListInsert1(L1, 1, 11);
    ListInsert1(L1, 2, 21);
	ListInsert1(L1, 3, 31);

    printList1(L1);
	//-------------------------2、动态存储线性表-------------------------
    SqList L2;
    InitList2(L2);
    ListInsert2(L2, 1, 12);
    ListInsert2(L2, 2, 22);
    ListInsert2(L2, 3, 32);

    SqList L22;
    InitList2(L22);
    ListInsert2(L22, 1, 22);
    ListInsert2(L22, 2, 32);
    ListInsert2(L22, 3, 82);
    ListInsert2(L22, 4, 92);

    printList2(L2);
    printList2(L22);

    //------------------------3、不带头结点的单链表------------------------
	LinkList L3;
    InitList3(L3);
	ListInsert3(L3, 1, 13);
	ListInsert3(L3, 2, 23);
	ListInsert3(L3, 3, 33);

	printList3(L3);

    //-------------------------4、带头结点的单链表-------------------------
	LinkList L4;
    InitList4(L4);
    ListInsert4(L4, 1, 14);
    ListInsert4(L4, 2, 24);
    ListInsert4(L4, 3, 34);

    printList4(L4);

    //----------------------------5、静态链表----------------------------
    SLinkList L5;
	InitList5(L5);
	ListInsert5(L5, 1, 15);
	ListInsert5(L5, 2, 25);
	ListInsert5(L5, 3, 35);

	ListTraverse5(L5, visit);

    //------------------6、带头结点的使用尾指针的单循环链表------------------
	LinkList L6;
	InitList6(L6);
	ListInsert6(L6, 1, 16);
	ListInsert6(L6, 2, 26);
	ListInsert6(L6, 3, 36);

	ListTraverse6(L6, visit);

    //------------------------7、带头结点的双向链表------------------------
	DuLinkList L7;
	InitList7(L7);
	ListInsertF7(L7, 1, 17);
	ListInsertF7(L7, 2, 27);
	ListInsertF7(L7, 3, 37);
    ListInsertR7(L7, 3, 47);
    ListInsertR7(L7, 4, 57);

	printList7(L7);

    //----------------------8、带头结点的双向循环链表----------------------
	DuLinkList L8;
	InitList8(L8);
	ListInsertF8(L8, 1, 18);
	ListInsertF8(L8, 2, 28);
	ListInsertF8(L8, 3, 38);
	ListInsertR8(L8, 3, 48);
	ListInsertR8(L8, 4, 58);

	ListTraverse8(L8, visit);
	ListTraverseBack8(L8, visit);

    return 0;
}
