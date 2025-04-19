#include "结构、常量定义及函数声明.h"

//1、初始化链式队列
Status InitQueue12(LinkQueue& Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)   return(OVERFLOW);
    Q.front->next = NULL;   //头结点的指针域置空
    return OK;
}

//2、销毁链式队列
Status DestroyQueue12(LinkQueue& Q) {
    QueuePtr p, temp;
    p = Q.front; // 从队头开始遍历     
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp); // 释放节点内存      
    }
    Q.front = Q.rear = NULL; // 将头尾指针置为空      
    return OK;
}

//3、判断链式队列是否为空
int isEmpty12(LinkQueue Q) {
    if (Q.front == Q.rear) return true;
    else return false;
}

//4、获取队头元素
Status GetFront12(LinkQueue Q, QElemType& e) {
    if (isEmpty12(Q)) return ERROR;
    e = Q.front->next->data;  return OK; //队头元素	  	
}

//5、入队
Status EnQueue12(LinkQueue& Q, QElemType e) {
    QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
    if (!q) {                //存储分配失败
        return(OVERFLOW);
    }
    q->data = e;
    q->next = NULL;
    if(isEmpty12(Q)) { Q.front->next = Q.rear = q; }
    else {
        Q.rear->next = q;    //先使rear指向结点的next指向新节点q
        Q.rear = q;          //再使尾指针指向q
        return OK;
    }
}

//6、出队
Status DeQueue12(LinkQueue& Q, QElemType& e) {
    //删去队头结点，并返回队头元素的值
    if (isEmpty12(Q)) return ERROR;	//判队空
    QNode* p = Q.front->next;  //p指向队头数据元素	
    e = p->data;			//保存队头的值
    Q.front->next = p->next; 	//新队头,修改头结点指针域
    if (Q.rear == p)      Q.rear = Q.front;
    //最后一个元素被删除，则对队尾指针重新赋值（指向头结点）
    free(p);
    return OK;
}

//打印队列
void printQueue12(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}