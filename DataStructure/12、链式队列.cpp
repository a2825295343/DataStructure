#include "�ṹ���������弰��������.h"

//1����ʼ����ʽ����
Status InitQueue12(LinkQueue& Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)   return(OVERFLOW);
    Q.front->next = NULL;   //ͷ����ָ�����ÿ�
    return OK;
}

//2��������ʽ����
Status DestroyQueue12(LinkQueue& Q) {
    QueuePtr p, temp;
    p = Q.front; // �Ӷ�ͷ��ʼ����     
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp); // �ͷŽڵ��ڴ�      
    }
    Q.front = Q.rear = NULL; // ��ͷβָ����Ϊ��      
    return OK;
}

//3���ж���ʽ�����Ƿ�Ϊ��
int isEmpty12(LinkQueue Q) {
    if (Q.front == Q.rear) return true;
    else return false;
}

//4����ȡ��ͷԪ��
Status GetFront12(LinkQueue Q, QElemType& e) {
    if (isEmpty12(Q)) return ERROR;
    e = Q.front->next->data;  return OK; //��ͷԪ��	  	
}

//5�����
Status EnQueue12(LinkQueue& Q, QElemType e) {
    QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
    if (!q) {                //�洢����ʧ��
        return(OVERFLOW);
    }
    q->data = e;
    q->next = NULL;
    if(isEmpty12(Q)) { Q.front->next = Q.rear = q; }
    else {
        Q.rear->next = q;    //��ʹrearָ�����nextָ���½ڵ�q
        Q.rear = q;          //��ʹβָ��ָ��q
        return OK;
    }
}

//6������
Status DeQueue12(LinkQueue& Q, QElemType& e) {
    //ɾȥ��ͷ��㣬�����ض�ͷԪ�ص�ֵ
    if (isEmpty12(Q)) return ERROR;	//�жӿ�
    QNode* p = Q.front->next;  //pָ���ͷ����Ԫ��	
    e = p->data;			//�����ͷ��ֵ
    Q.front->next = p->next; 	//�¶�ͷ,�޸�ͷ���ָ����
    if (Q.rear == p)      Q.rear = Q.front;
    //���һ��Ԫ�ر�ɾ������Զ�βָ�����¸�ֵ��ָ��ͷ��㣩
    free(p);
    return OK;
}

//��ӡ����
void printQueue12(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}