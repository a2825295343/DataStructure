#define ListSize 100    //最大允许长度
typedef int ElemType;    //线性表数据类型

typedef  struct {
    ElemType  data[ListSize];    //存储空间
    int  length;         //当前元素个数
} SeqList;

//初始化表L为空表
void InitList(SeqList& L)
{                                 
    L.length = 0;
}

//回收线性表L
void DestroyList(SeqList& L)
{
    L.length = 0;
}

