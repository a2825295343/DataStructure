#include "�ṹ���������弰��������.h"

//1������������
int GListDepth16(GList L)
{   // ����ͷβ����洢�ṹ,������L����ȡ�
    if (!L) return 1;    //�ձ����Ϊ1
    if (L->tag == ATOM)   return 0;  //ԭ�����Ϊ0
    int max,dep = 0;
	GList pp = L; //ppָ���ͷ���
    for (max = 0, pp = L; pp; pp = pp->ptr.tp) {
        dep = GListDepth16(pp->ptr.hp); //����pp->ptr.hpΪͷָ����ӱ���ȣ��ݹ飩
            if (dep > max)   max = dep;
    }
    return max + 1;   //�ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
}// GListDepth

//2��������ĳ���
int GListLength16(GList L)
{ //������L�ĳ��ȣ��ǵݹ飩,��Ԫ�ظ���
    int len = 0;
    GList p;
    if (L->tag == LIST && !L->ptr.hp)   return 0;   // �ձ���0
    else if (L->tag == ATOM) return 1;              // ��ԭ�ӱ�
    else {                                          // һ���
        p = L->ptr.hp;
        do
        {
            len++;
            p = p->ptr.tp;
        } while (p);
        return len;
    }
}

//3��������ĳ��ȣ��ݹ�棩
int LengthRecur16(GLNode* GL) {
    if (GL == NULL) return 0; //�����Ϊ��ʱ
    else return 1 + LengthRecur16(GL->ptr.tp); //����Ϊ��β�ĳ���+1
}

//��ӡ�����
void printGList16(GList L) {
	if (L == NULL) return; //�ձ�
	if (L->tag == ATOM) { //ԭ�ӽ��
		printf("%d ", L->atom);
	}
	else { //����
		printf("(");
		printGList16(L->ptr.hp); //��ӡ��ͷ
		printf(")");
		if (L->ptr.tp != NULL) { //��ӡ��β
			printf(",");
			printGList16(L->ptr.tp);
		}
	}
}
