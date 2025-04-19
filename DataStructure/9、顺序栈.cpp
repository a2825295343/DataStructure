#include "结构、常量定义及函数声明.h"

//需要注意：该文件下定义的函数默认top指针指向栈顶元素的下一个位置，而非栈顶元素所在位置，
//实际上完全可以将top指针指向栈顶元素所在位置，结构并不是固定死的，需要举一反三。

//1、初始化顺序栈
Status InitStack9(SqStack& S) {   //建空栈
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW); 	//存储分配失败
	S.top = S.base;
	S.StackSize = STACK_INIT_SIZE;
	return OK;
}

//2、销毁顺序栈
Status DestroyStack9(SqStack& S)
{
	if (S.base)
	{
		free(S.base);
		S.StackSize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//3、清空顺序栈
Status ClearStack9(SqStack S)
{
	if (S.base)
		S.top = S.base;
	return OK;
}

//4、判断栈是否为空
Status StackEmpty9(SqStack& S) {
	if (S.top == S.base) return TRUE; //栈空
	else return FALSE;
}

//5、判断栈是否满
Status StackFull9(SqStack& S) {
	if (S.top - S.base >= S.StackSize) 	   //栈满
		return TRUE;
	else return FALSE;
}

//6、求栈的长度
int StackLength9(SqStack S)
{
	return S.top - S.base;
}

//7、获取栈顶元素
Status GetTop9(SqStack S, SElemType& e)
{//若栈空返回ERROR, 否则栈顶元素读到e并返回OK
	if (S.top == S.base)	 return ERROR; 	// 栈空
	e = *(S.top - 1);
	return OK;
}

//8、入栈
Status Push9(SqStack& S, SElemType e) {
	//插入元素e为新的栈顶元素 
	if (StackFull9(S)) { //栈满
		S.base = (SElemType*)realloc(S.base,
			(S.StackSize + STACKINCREMENT) * sizeof(SElemType)); //追加存储空间
		if (!S.base)	exit(OVERFLOW);
		S.top = S.base + S.StackSize;//栈顶指针 指向新的栈顶
		S.StackSize += STACKINCREMENT; //更新当前已分配空间
	}
	*(S.top)++ = e;
	return OK;
}

//9、出栈
Status Pop9(SqStack& S, SElemType& e)
{//若栈空返回ERROR, 否则删除栈顶元素，用e返回其值.
	if (S.top == S.base) // 栈空
		return ERROR;
	e = * --S.top;   //栈顶指针减1后，将栈顶元素赋值给e
	return OK;
}

//打印栈中元素
void printStack9(SqStack S) {
	//打印栈中元素
	if (S.base == NULL) {
		printf("栈为空\n");
		return;
	}
	for (int i = 0; i < StackLength9(S); i++)
		printf("%d ", *(S.base + i));
	printf("\n");
}