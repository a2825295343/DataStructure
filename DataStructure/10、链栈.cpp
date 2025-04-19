#include "�ṹ���������弰��������.h"

//1����ʼ��
Status InitStack10(LinkStack& S) {
	S.top = NULL;
	return OK;
}

//2���ж��Ƿ�Ϊ��
Status StackEmpty10(LinkStack S) {
	return S.top == NULL;
}

//3��ȡջ��Ԫ��
Status GetTop10(LinkStack S, SElemType& e) {
	if (StackEmpty10(S)) return ERROR;
	e = S.top -> data;
	return OK;
}

//4����ջ
Status Push10(LinkStack& S, SElemType e) {
	Link q = (Link)malloc(sizeof(StackNode));
	if (!q) exit(OVERFLOW);
	//�����½��q
	q -> data = e;
	q -> next = S.top;
	S.top = q;
	return OK;
}

//5����ջ
Status Pop10(LinkStack& S, SElemType& e) {
	Link q = S.top;
	if (StackEmpty10(S)) return ERROR;
	e = q -> data;
	S.top = q -> next;
	free(q);
	return OK;
}

//��ӡջ
void printStack10(LinkStack S) {
	Link p = S.top;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}