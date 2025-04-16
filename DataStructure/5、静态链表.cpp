#include "�ṹ���������弰��������.h"

//1������������ǿ�,�򷵻ط���Ľ���±�(��������ĵ�һ�����);���򷵻�0
int Malloc5(SLinkList space)
{
    int i = space[0].cur; //���������һ������λ��

    if (i) //��������ǿ�
        space[0].cur = space[i].cur;
    //���������ͷ���ָ��ԭ��������ĵڶ������
    return i;  //�����¿��ٽ�������
}

//2�����ս��k,������뱸�������У���Ϊ��������ĵ�һ���ڵ�
void Free5(SLinkList space, int k)
{
    space[k].cur = space[0].cur;
    //���ս��ġ��αꡱָ��������ĵ�һ�����
    space[0].cur = k;
    //���������ͷ���ָ���»��յĽ��
}

//3������һ���յ�����L����ͷΪL�����һ����Ԫ[MAX SIZE-1]�����൥Ԫ����һ������������ͷΪL�ĵ�һ����ԪL[0]����0����ʾ��ָ�롣
void InitList5(SLinkList L)
{
    int i;
    L[MAX_SIZE - 1].cur = 0;
    //L�����һ����ԪΪ������ı�ͷ
    for (i = 0; i < MAX_SIZE - 2; i++)
        //�����൥Ԫ���ӳ���[0]Ϊ��ͷ�ı�������
        L[i].cur = i + 1;
    L[MAX_SIZE - 2].cur = 0;
}

//4���������L
void ClearList5(SLinkList L)
{ //��ʼ����:���Ա�L�Ѵ��ڡ��������:��L����Ϊ�ձ�
    int j, i = L[0].cur; //iָʾ���������һ������λ��
    while (i)
    {
        j = i; //jָʾ��ǰ����λ��
        i = L[i].cur; //iָ����һ������λ��
    }
    L[j].cur = L[MAX_SIZE - 1].cur;
    //����ĵ�һ�����ӵ����������β��
    L[MAX_SIZE - 1].cur = 0; //�����
}

//5���ж�����L�Ƿ�Ϊ��
Status ListEmpty5(SLinkList L)
{ //��L�ǿձ�����TRUE;���򷵻�FALSE
    if (L[MAX_SIZE - 1].cur == 0)
        //�ձ�(��ͷ����cur��Ϊ0)
        return TRUE;
    else
        return FALSE;
}

//6��������L�ĳ���
int ListLength5(SLinkList L)
{//����L������Ԫ�ظ���
    int j = 0, i = L[MAX_SIZE - 1].cur;
    //iָʾ����ĵ�һ������λ��
    while (i) //δ����̬����β
    {
        i = L[i].cur; //iָ����һ�����
        j++; //������+1
    }
    return j;
}

//7����ȡ����L�е�i��Ԫ��
Status GetElem5(SLinkList L, int i, ElemType& e)
{  //��e����L�е�i��Ԫ�ص�ֵ
    int m, k = MAX_SIZE - 1; //kָʾ��ͷ����λ��
    if (i<1 || i>ListLength5(L)) //�����ڵ�i��Ԫ��
        return ERROR;
    for (m = 1; m <= i; m++) //k����ƶ�����i��Ԫ�ش�
        k = L[k].cur; //ָ����һ��Ԫ��
    e = L[k].data; //����i��Ԫ�ص�ֵ����e
    return OK;
}

//8���ھ�̬����L�в���ֵΪe��Ԫ�أ���������L�е�λ��
int LocateElem5(SLinkList L, ElemType e)
{//�ھ�̬�������Ա�L�Ж��ҵ�һ��ֵΪe��Ԫ�ء����ҵ����򷵻�����L�е�λ��;���򷵻�0
//(������ LocatElem()�Ķ��岻ͬ)

    int i = L[MAX_SIZE - 1].cur; //iָʾ���е�һ������λ��
    while (i && L[i].data != e)
        //�ڱ���˳������(e�������ַ���)���ҵ����ѵ���β������ѭ��
        i = L[i].cur; //ָ����һ��Ԫ��
    return i;
}

//9���ھ�̬����L�в���ֵΪcur_e��Ԫ�أ���������ֱ�Ӻ��
Status NextElem5(SLinkList L, ElemType cur_e, ElemType& next_e)
{//��ʼ����:���Ա�L�Ѵ���; 
//�������:��cur_e��L������Ԫ�أ��Ҳ������һ�������� next e�������ĺ��;�������ʧ�ܣ�next_e�޶���
    int j, i = LocateElem5(L, cur_e); //��L�Ж��ҵ�һ��ֵΪcur_e��Ԫ�ص�λ��f(i)/L�д���Ԫ��cur_e
    if (i) //L�д���Ԫ��cur_e
    {
        j = L[i].cur; //jָʾcur_e�ĺ�̵�λ��if(j)
        if (j)     //cur_e�к��
        {
            next_e = L[j].data;
            //��cure�ĺ�����ݸ��� next_e
            return OK;
        }
    }
    return ERROR; //L������cureԪ�أ���cureԪ���޺��
}

//10���ھ�̬����L�в���ֵΪcur_e��Ԫ�أ���������ֱ��ǰ��
Status PriorElem5(SLinkList L, ElemType cur_e, ElemType& pre_e)
{    //��ʼ���������Ա�L�Ѵ��ڡ�//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��;  
    int j, i = L[MAX_SIZE - 1].cur; //iָʾ�����һ������λ��
    do  //����ƶ����
    {
        j = i; //jָ��i��ָԪ��
        i = L[i].cur; //iָ����һ��Ԫ��
    } while (i && cur_e != L[i].data);
    //i��ָԪ�ش�������ֵ����cur_e������ѭ��
    if (i) //�ҵ���Ԫ��
    {
        pre_e = L[j].data; //��ָԪ����i��ָԪ�ص�ǰ��Ԫ�أ�����pre_e
        return OK;
    }
    return ERROR; //δ�ҵ���Ԫ�أ�������ǰ��
}

//11���ھ�̬����L�е�i��Ԫ��ǰ����Ԫ��e
Status ListInsert5(SLinkList L, int i, ElemType e)
//��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
{
    int m, j, k = MAX_SIZE - 1; //kָʾ��ͷ����λ��
    if (i<1 || i>ListLength5(L) + 1) //iֵ���Ϸ�
        return ERROR;
    j = Malloc5(L); //�����µ�Ԫ
    if (j) //����ɹ�
    {
        L[j].data = e; //��e��ֵ���µ�Ԫ
        for (m = 1; m < i; m++) //k����ƶ�i-1�����,ʹkָʾ��i-1�����
            k = L[k].cur; //ָ����һ�����
        L[j].cur = L[k].cur; //�µ�Ԫָ���i-1��Ԫ�غ����Ԫ��(��i��Ԫ��)
        L[k].cur = j; //��i-1��Ԫ��ָ���µ�Ԫ
        return OK;
    }
    return ERROR;
}

//12���ھ�̬����L��ɾ����i��Ԫ��
Status ListDelete5(SLinkList L, int i, ElemType& e)
{ //ɾ����L�е�i������Ԫ��e����������ֵ
    int j, k = MAX_SIZE - 1; //kָʾ��ͷ����λ��
    if (i<1 || i>ListLength5(L)) //iֵ���Ϸ�
        return ERROR;
    for (j = 1; j < i; j++) //�ƶ�i-1��Ԫ�أ�ʹkָ���i-1��Ԫ��
        k = L[k].cur; //ָ����һ��Ԫ��
    j = L[k].cur; //��ɾ��Ԫ��(��i��Ԫ��)��λ�ø���j
    L[k].cur = L[j].cur; // ʹ��i-1��Ԫ��ָ���ɾ��Ԫ�صĺ��Ԫ��
    e = L[j].data; //��ɾ��Ԫ�ص�ֵ����e
    Free5(L, j); //�ͷŴ�ɾ�����(���յ�����������)
    return OK;
}

//13��������̬����L�е�Ԫ��
void ListTraverse5(SLinkList L, void(*visit)(ElemType))
{//��ʼ����:���Ա�L�Ѵ��ڡ�
//������������ζ�L��ÿ������Ԫ�ص��ú���
    int i = L[MAX_SIZE - 1].cur; //iָʾ��һ��Ԫ�ص�λ��
    while (i)  //δ����̬����β
    { visit(L[i].data); //�Ե�ǰԪ�ص��� visit() 
      i = L[i].cur; //ָ����һ��Ԫ��
    }
    printf("\n");
}
