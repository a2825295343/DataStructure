#define ListSize 100    //���������
typedef int ElemType;    //���Ա���������

typedef  struct {
    ElemType  data[ListSize];    //�洢�ռ�
    int  length;         //��ǰԪ�ظ���
} SeqList;

//��ʼ����LΪ�ձ�
void InitList(SeqList& L)
{                                 
    L.length = 0;
}

//�������Ա�L
void DestroyList(SeqList& L)
{
    L.length = 0;
}

