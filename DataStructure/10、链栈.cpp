#include "结构、常量定义及函数声明.h"

//1、初始化
Status InitStack10(LinkStack& S) {
	S.top = NULL;
	return OK;
}

//2、判断是否为空
Status StackEmpty10(LinkStack S) {
	return S.top == NULL;
}

//3、取栈顶元素
Status GetTop10(LinkStack S, SElemType& e) {
	if (StackEmpty10(S)) return ERROR;
	e = S.top -> data;
	return OK;
}

//4、入栈
Status Push10(LinkStack& S, SElemType e) {
	Link q = (Link)malloc(sizeof(StackNode));
	if (!q) exit(OVERFLOW);
	//生成新结点q
	q -> data = e;
	q -> next = S.top;
	S.top = q;
	return OK;
}

//5、出栈
Status Pop10(LinkStack& S, SElemType& e) {
	Link q = S.top;
	if (StackEmpty10(S)) return ERROR;
	e = q -> data;
	S.top = q -> next;
	free(q);
	return OK;
}

//打印栈
void printStack10(LinkStack S) {
	Link p = S.top;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}