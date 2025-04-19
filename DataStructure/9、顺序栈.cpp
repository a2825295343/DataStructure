#include "�ṹ���������弰��������.h"

//��Ҫע�⣺���ļ��¶���ĺ���Ĭ��topָ��ָ��ջ��Ԫ�ص���һ��λ�ã�����ջ��Ԫ������λ�ã�
//ʵ������ȫ���Խ�topָ��ָ��ջ��Ԫ������λ�ã��ṹ�����ǹ̶����ģ���Ҫ��һ������

//1����ʼ��˳��ջ
Status InitStack9(SqStack& S) {   //����ջ
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW); 	//�洢����ʧ��
	S.top = S.base;
	S.StackSize = STACK_INIT_SIZE;
	return OK;
}

//2������˳��ջ
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

//3�����˳��ջ
Status ClearStack9(SqStack S)
{
	if (S.base)
		S.top = S.base;
	return OK;
}

//4���ж�ջ�Ƿ�Ϊ��
Status StackEmpty9(SqStack& S) {
	if (S.top == S.base) return TRUE; //ջ��
	else return FALSE;
}

//5���ж�ջ�Ƿ���
Status StackFull9(SqStack& S) {
	if (S.top - S.base >= S.StackSize) 	   //ջ��
		return TRUE;
	else return FALSE;
}

//6����ջ�ĳ���
int StackLength9(SqStack S)
{
	return S.top - S.base;
}

//7����ȡջ��Ԫ��
Status GetTop9(SqStack S, SElemType& e)
{//��ջ�շ���ERROR, ����ջ��Ԫ�ض���e������OK
	if (S.top == S.base)	 return ERROR; 	// ջ��
	e = *(S.top - 1);
	return OK;
}

//8����ջ
Status Push9(SqStack& S, SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ�� 
	if (StackFull9(S)) { //ջ��
		S.base = (SElemType*)realloc(S.base,
			(S.StackSize + STACKINCREMENT) * sizeof(SElemType)); //׷�Ӵ洢�ռ�
		if (!S.base)	exit(OVERFLOW);
		S.top = S.base + S.StackSize;//ջ��ָ�� ָ���µ�ջ��
		S.StackSize += STACKINCREMENT; //���µ�ǰ�ѷ���ռ�
	}
	*(S.top)++ = e;
	return OK;
}

//9����ջ
Status Pop9(SqStack& S, SElemType& e)
{//��ջ�շ���ERROR, ����ɾ��ջ��Ԫ�أ���e������ֵ.
	if (S.top == S.base) // ջ��
		return ERROR;
	e = * --S.top;   //ջ��ָ���1�󣬽�ջ��Ԫ�ظ�ֵ��e
	return OK;
}

//��ӡջ��Ԫ��
void printStack9(SqStack S) {
	//��ӡջ��Ԫ��
	if (S.base == NULL) {
		printf("ջΪ��\n");
		return;
	}
	for (int i = 0; i < StackLength9(S); i++)
		printf("%d ", *(S.base + i));
	printf("\n");
}