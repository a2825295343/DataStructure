#include "�ṹ���������弰��������.h"

//ע��Ϊ������ӿ���������ڸ��ļ��¶����ѭ�����нṹ���У�ʹ�õ�������һ���洢��Ԫ�ķ�ʽ��
//��������ͨ������һ�������������־������ʵ�֣���Ҫ��һ������

//1����ʼ��ѭ������
Status InitQueue11(SqQueue& Q) {
	//����ն���
	Q.data = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	if(!Q.data)   exit(OVERFLOW);
	Q.rear = Q.front = 0;
	return OK;
}

//2����ѭ�����еĳ���
int QueueLength11(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//3���ж�ѭ�������Ƿ�Ϊ��
int QueueEmpty11(SqQueue& Q) {
	return Q.rear == Q.front;
}

//4���ж�ѭ�������Ƿ�����
int QueueFull11(SqQueue& Q) {
	return (Q.rear + 1) % MAXSIZE == Q.front;
}

//5�����
Status EnQueue11(SqQueue& Q, QElemType e) {
	if (QueueFull11(Q)) return ERROR;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

//6������
Status DeQueue11(SqQueue& Q, QElemType& e) {
	if (QueueEmpty11(Q)) return ERROR;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

//7��ȡ��ͷԪ��
Status GetFront11(SqQueue& Q, QElemType& e) {
	if (QueueEmpty11(Q)) return ERROR;
	e = Q.data[Q.front];
	return OK;
}

//��ӡ����
void printQueue11(SqQueue Q) {
	int i = Q.front;
	while (i != Q.rear) {
		printf("%d ", Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}