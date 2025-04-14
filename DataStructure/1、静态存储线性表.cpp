#include "�ṹ���������弰��������.h"

//1����ʼ����LΪ�ձ�
void InitList1(SeqList& L)
{                                 
    L.length = 0;
}

//2���������Ա�L
void DestroyList1(SeqList& L)
{
    L.length = 0;
}

//3��������Ա�L
void ClearList1(SeqList& L)         
{
    L.length = 0;
}

//4�������Ա�LΪ�շ���1,���򷵻�0
int  ListEmpty1(SeqList L) { 
    return(!(L.length));
}

//5������ֵ�Ǳ�L�ĳ���
int ListLength1(SeqList L)
{                                                       
    return(L.length);
}

//6����ȡ��L�е� i ��Ԫ��
ElemType GetElem1(SeqList L, int i) { 
    if (1 <= i && i <= L.length)
        return (L.data[i - 1]); //��i-1�ĵ�Ԫ�洢�ŵ�i������
    else  return NULL;
}

//7�������Ա�L�в���ֵΪe������Ԫ�أ�������λ��
int LocateELem1(SeqList L, ElemType e)
{                                                  
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e) return i + 1;
    return ERROR;
}

//8���ж�x�Ƿ��ڱ�L��
int IsIn1(SeqList L, ElemType x) {  
    //x��L�з���OK�����򷵻�ERROR
    int  i = 0, found = ERROR;
    while ((i < L.length) && !found)
        if (L.data[i] != x) i++;
        else found = OK;
    return found;
}

//9�����L��Ԫ��x��ֱ�Ӻ��
int NextElem1(SeqList L, ElemType x) { //���x�ڱ�L����
    //��ֱ�Ӻ�̣�����ֵ������ֱ�Ӻ�̵�λ�ã����򷵻�-1
    int i = 0;
    while ((i < L.length) && (L.data[i] != x)) i++;    //����x
    if ((0 <= i) && (i < L.length - 1)) return i + 1;
    else return ERROR;
}

//10�����L��Ԫ��x��ֱ��ǰ��
int PriorElem1(SeqList L, ElemType x) {   //���x�ڱ�L����
    //��ֱ��ǰ��������ֵ������ֱ��ǰ����λ�ã����򷵻�-1
    int i = 0;
    while (i < L.length && L.data[i] != x) i++;          //����x 
    if ((0 < i) && (i < L.length)) return i - 1;     //����λ�� 
    else return ERROR;
}

//11����˳���L�е� i ��Ԫ��ǰ���� x,����ɹ�����OK�����ɹ� ����ERROR
int ListInsert1(SeqList& L, int i, ElemType x) {  //��˳���L��
    //�� i ��Ԫ��ǰ���� x,����ɹ�����OK�����ɹ� ����ERROR
    if ((i < 1) || (i > L.length + 1) || (L.length == ListSize))
        return ERROR;                           //���벻�ɹ�	
    else {
        for (int j = L.length; j > i - 1; j--)                //����
            L.data[j] = L.data[j - 1];
        L.data[i - 1] = x;   L.length++;  return OK;     //����ɹ�       
    }
}

//12����˳���L��ɾ���� i ��Ԫ��,�ɹ�����OK�����򷵻�ERROR
int ListDelete1(SeqList& L, int  i) {//��˳���L��ɾ����i��Ԫ��,
    //�ɹ�����OK�����򷵻�ERROR
    if ((i < 1) || (i > L.length)) return ERROR;
    L.length--;
    for (int j = i - 1; j < L.length + 1; j++)        //ǰ��
        L.data[j] = L.data[j + 1];
    return OK;                                           //�ɹ�ɾ��	
}

//��ӡ���Ա�L
void printList1(SeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}