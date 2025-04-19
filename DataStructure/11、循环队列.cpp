#include "结构、常量定义及函数声明.h"

//注：为了区别队空与队满，在该文件下定义的循环队列结构体中，使用的是少用一个存储单元的方式，
//而还可以通过设置一个计数变量或标志变量来实现，需要举一反三。

//1、初始化循环队列
Status InitQueue11(SqQueue& Q) {
	//构造空队列
	Q.data = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	if(!Q.data)   exit(OVERFLOW);
	Q.rear = Q.front = 0;
	return OK;
}

//2、求循环队列的长度
int QueueLength11(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//3、判断循环队列是否为空
int QueueEmpty11(SqQueue& Q) {
	return Q.rear == Q.front;
}

//4、判断循环队列是否已满
int QueueFull11(SqQueue& Q) {
	return (Q.rear + 1) % MAXSIZE == Q.front;
}

//5、入队
Status EnQueue11(SqQueue& Q, QElemType e) {
	if (QueueFull11(Q)) return ERROR;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

//6、出队
Status DeQueue11(SqQueue& Q, QElemType& e) {
	if (QueueEmpty11(Q)) return ERROR;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

//7、取队头元素
Status GetFront11(SqQueue& Q, QElemType& e) {
	if (QueueEmpty11(Q)) return ERROR;
	e = Q.data[Q.front];
	return OK;
}

//打印队列
void printQueue11(SqQueue Q) {
	int i = Q.front;
	while (i != Q.rear) {
		printf("%d ", Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}