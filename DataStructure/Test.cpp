#include "�ṹ���������弰��������.h"

int main() {
	//------------------1����̬�洢���Ա�------------------
	SeqList L1;
    InitList1(L1);
    ListInsert1(L1, 1, 11);
    ListInsert1(L1, 2, 21);
	ListInsert1(L1, 3, 31);

    printList1(L1);
	//------------------2����̬�洢���Ա�------------------
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

    //------------------3������ͷ���ĵ�����------------------
	LinkList L3;
    InitList3(L3);
	ListInsert3(L3, 1, 13);
	ListInsert3(L3, 2, 23);
	ListInsert3(L3, 3, 33);

	printList3(L3);

    //------------------4����ͷ���ĵ�����------------------
	LinkList L4;
    InitList4(L4);
    ListInsert4(L4, 1, 14);
    ListInsert4(L4, 2, 24);
    ListInsert4(L4, 3, 34);

    printList4(L4);


    return 0;
}
