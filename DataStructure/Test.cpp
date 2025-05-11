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

	//-----------------------------9、顺序栈-----------------------------
	SqStack S9;
	InitStack9(S9);
	Push9(S9, 19);
	Push9(S9, 29);
	Push9(S9, 39);

	printStack9(S9);

	//-----------------------------10、链栈-----------------------------
	LinkStack S10;
	InitStack10(S10);
	Push10(S10, 110);
	Push10(S10, 210);
	Push10(S10, 310);

	printStack10(S10);

	//---------------------------11、循环队列---------------------------
	SqQueue Q11;
	InitQueue11(Q11);
	EnQueue11(Q11, 111);
	EnQueue11(Q11, 211);
	EnQueue11(Q11, 311);

	printQueue11(Q11);

	//---------------------------12、链式队列---------------------------
	LinkQueue Q12;
	InitQueue12(Q12);
	EnQueue12(Q12, 112);
	EnQueue12(Q12, 212);
	EnQueue12(Q12, 312);

	printQueue12(Q12);

	//-----------------------------13、数组-----------------------------
	Array A13;
	InitArray13(A13, 2, 3, 4, 5);
	Assign13(A13, 1, 1, 1, 1);

	//printArray13(A13);

	//----------------------14、稀疏矩阵的三元组存储----------------------
	TSMatrix M14;
	/*M14.mu = 4;
	M14.nu = 4;
	M14.tu = 4;
	M14.data[0].i = 1;
	M14.data[0].j = 1;
	M14.data[0].e = 1;
	M14.data[1].i = 2;
	M14.data[1].j = 2;
	M14.data[1].e = 2;
	M14.data[2].i = 3;
	M14.data[2].j = 3;
	M14.data[2].e = 3;
	M14.data[3].i = 4;
	M14.data[3].j = 4;
	M14.data[3].e = 4;*/

	//printMatrix14(M14);

	//----------------------15、稀疏矩阵的十字链表存储----------------------
	CrossList M15 = { nullptr, nullptr, 0, 0, 0 };
	CreateSMatrix_OL15(M15);

	printMatrix15(M15);

	//----------------------16、广义表的头尾链表存储----------------------
	GList L16;
	/*L16 = (GList)malloc(sizeof(GLNode));
	L16->tag = LIST;
	L16->ptr.hp = (GList)malloc(sizeof(GLNode));
	L16->ptr.hp->tag = ATOM;
	L16->ptr.hp->atom = 1;
	L16->ptr.tp = (GList)malloc(sizeof(GLNode));
	L16->ptr.tp->tag = LIST;
	L16->ptr.tp->ptr.hp = (GList)malloc(sizeof(GLNode));
	L16->ptr.tp->ptr.hp->tag = ATOM;
	L16->ptr.tp->ptr.hp->atom = 2;
	L16->ptr.tp->ptr.tp = (GList)malloc(sizeof(GLNode));
	L16->ptr.tp->ptr.tp->tag = LIST;
	L16->ptr.tp->ptr.tp->ptr.hp = (GList)malloc(sizeof(GLNode));
	L16->ptr.tp->ptr.tp->ptr.hp->tag = ATOM;
	L16->ptr.tp->ptr.tp->ptr.hp->atom = 3;*/

	//printGList16(L16);

    return 0;
}
