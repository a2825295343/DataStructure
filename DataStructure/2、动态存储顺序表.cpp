//#include <stdlib.h>
#include "�ṹ���������弰��������.h"
//#define ERROR 0         //�����־
//#define OK 1            //�ɹ���־
//typedef int ElemType;    //���Ա���������
//
//#define LIST_INIT_SIZE  12	             // ���Ա�洢�ռ�ĳ�ʼ������
//#define LISTINCREMENT  4		// ���Ա�洢�ռ�ķ�������
//
//typedef struct
//{
//	ElemType* data;	        // �洢�ռ��ַ
//	int length;		        // ˳���ǰ����
//	int listsize;	       // ��ǰ����Ĵ洢����(��sizeof(ListData)Ϊ��λ)
//}SqList;
//1����ʼ����LΪ�ձ�
int InitList2(SqList& L)
{                                	// ����ָ����С�Ĵ洢�ռ��˳���
	L.data = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));   //����洢��Ԫ
	if (!L.data)             // �洢����ʧ��
		return ERROR;
	L.length = 0;             // ��ǰ���ȳ�ʼ��Ϊ0
	L.listsize = LIST_INIT_SIZE; // ָ������Ĵ洢����	
	return OK;
}

//2������˳�����Ա�L����˳���ṹ���е����г�Ա���٣��ռ��ͷţ� ��ֵ��0��
int DestroyList2(SqList& L)
{                    	// ���ͷſռ䣬Ȼ���ÿ�
	free(L.data);
	L.length = 0;
	L.listsize = 0;
	return OK;
}

//3��������Ա�L
int ClearList2(SqList& L)
{                   //������Ա�L
	L.length = 0;
	return OK;
}

//4�������Ա�LΪ�շ���1,���򷵻�0
int ListEmpty2(SqList L)
{
	return(!(L.length));
}

//5�����L�ĳ���
int  ListLength2(SqList L)
{
	// L.length��¼��ǰ˳���ĳ��ȣ�ֱ�ӷ���
	return (L.length);
}

//6����ȡ��L�е� i ��Ԫ��
ElemType GetElem2(SqList L, int i) {//����ֵΪ��L��
	//�� i ��Ԫ��
	if (1 <= i && i <= L.length)
		return (*(L.data + i - 1));
	else return NULL;
}

//7�������Ա�L�в���ֵΪx������Ԫ�أ�������λ��
int  LocateElem2(SqList L, ElemType x) {//����x�ڱ�   
	//L��λ��, �����ҳɹ�������x��λ�ã����򷵻�ERROR
	int i = 0;
	while ((i < L.length) && (*(L.data + i) != x)) i++;   //����
	if (i < L.length) return i;                    //�ɹ�,����λ��
	else return -1;                             //ʧ��
}

//8���ж�x�Ƿ��ڱ�L��
int IsIn2(SqList L, ElemType x) {  //�ж�x�Ƿ��ڱ�L��
	//x��L�з���1�����򷵻�0
	int i = 0, found = ERROR;
	while ((i < L.length) && !found)
		if (*(L.data + i) != x) i++;
		else found = OK;
	return found;
}

//9���ڱ�L����x��ֱ�Ӻ��
int  NextElem2(SqList L, ElemType x) { //���x�ڱ�L����
	//��ֱ�Ӻ�̣�����ֵ������ֱ�Ӻ�̵�λ�ã����򷵻�ERROR
	int i = 0;
	while ((i < L.length) && (*(L.data + i) != x)) i++;    //����x
	if ((0 <= i) && (i < L.length - 1)) return i + 1;
	else return ERROR;
}

//10���ڱ�L����x��ֱ��ǰ��
int PriorElem2(SqList L, ElemType x) {   //���x�ڱ�L����
	//��ֱ��ǰ��������ֵ������ֱ��ǰ����λ�ã����򷵻�-1
	int i = 0;
	while (i < L.length && *(L.data + i) != x) i++;          //����x 
	if ((0 < i) && (i < L.length)) return i - 1;
	else return ERROR;
}

//11�������Ա�L�е�i��Ԫ��ǰ����e
int ListInsert2(SqList& L, int i, ElemType e)
{
	ElemType* newbase, * q, * p;
	if ((i < 1) || (i > L.length + 1)) return ERROR;          //�����i���Ϸ�
	if (L.length == L.listsize)                           // ��ǰ�洢�ռ�����, ���ӷ���ռ�
	{           // realloc�ı�L.data��ָ�ڴ�Ĵ�С��ԭʼ��ָ�ڴ��е����ݲ��䡣
		newbase = (ElemType*)realloc(L.data, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) return ERROR;                       //�����¿ռ�ʧ��
		L.data = newbase;                                      // �»�ַ
		L.listsize += LISTINCREMENT;                   // ���Ӵ洢����
	}
	q = L.data + i - 1;                                    // ָ�������λ��
	for (p = L.data + L.length - 1; p >= q; --p)   *(p + 1) = *p;     // q֮���Ԫ������
	*q = e;	 ++L.length;	return OK;                         // ����e ������1 
}

//12����˳���L��ɾ����i��Ԫ��
int ListDelete2(SqList& L, int i)
{
	ElemType* p, * q;
	if (i < 1 || i > L.length)  return ERROR;          // iֵ���Ϸ�
	p = L.data + i - 1;			 // pΪ��ɾ��Ԫ�ص�λ��
	q = L.data + L.length - 1;	              // ��βԪ�ص�λ��
	for (++p; p <= q; ++p)			// ��ɾ��Ԫ��֮���Ԫ������
		*(p - 1) = *p;
	L.length--;					// ����1
	return OK;
}

//13�����ϵġ���������
void Union2(SqList& A, SqList B) {
	int n = ListLength2(A);
	int m = ListLength2(B);
	for (int i = 1; i < m+1; i++) {
		ElemType x = GetElem2(B, i);  //��B��ȡһԪ��
		int k = LocateElem2(A, x);   //��A�в�����
		if (k == -1)                          //��δ�ҵ�������
		{
			ListInsert2(A, n, x);  n++;		
		}
	}
}

//14�����ϵġ���������
void Intersection2(SqList& A, SqList B) {
	int n = ListLength2(A);
	int m = ListLength2(B);
	int i = 0;
	while (i < n) {
		int x = GetElem2(A, i);          //��A��ȡ��i��Ԫ��
		int k = LocateElem2(B, x);        //��B����iλ��
		if (k == -1) { ListDelete2(A, i);  n--; }
		else i++;                            //δ�ҵ���A��ɾ����
	}
}

//��ӡ���Ա�L
void printList2(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}