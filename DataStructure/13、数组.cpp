#include "�ṹ���������弰��������.h"

//1����ʼ������
Status InitArray13(Array& A, int dim,...) {
    //��ά��dim�͸�ά���ȺϷ���������Ӧ������A
    if (dim<1 || dim>MAX_ARRAY_DIM) return ERROR;
    A.dim = dim;
    A.bounds = (int*)malloc(dim * sizeof(int));
    if (!A.bounds) exit(OVERFLOW);
        //����ά���ȺϷ�,����A.bounds,��Ԫ������elemtotal
        int elemtotal = 1;
		va_list ap; //����䳤������ap
        va_start(ap, dim); //�䳤������...�����β�dim֮��ʼ
    //apΪva_list���ͣ��Ǵ�ű䳤��������Ϣ������
    for (int i = 0; i < dim; ++i) {
        A.bounds[i] = va_arg(ap, int); //��һ���䳤��������A.bounds[i]��//A.bounds�����У���ŵ��Ǹ�ά�Ĵ�С��
        if (A.bounds[i] < 0) return UNDERFLOW; //��math.h�ж���Ϊ4
        else elemtotal *= A.bounds[i]; //����Ԫ������=��ά����֮�˻�
    }
    va_end(ap); //������ȡ�䳤����
    A.base = (ElemType*)malloc(elemtotal * sizeof(ElemType)); //��̬��������洢�ռ�
    //���½����ΰ�����ά�����߼��Ƕȶ�λԪ�ص����⡣Ҳ����˵�����ڶ�ά����������±꣨����Ч��Χ�ڣ���Ԫ�أ�ת������һά���ռ�����±�Ӧ����ʲô����������ˡ���ά���顱�Ĵ洢���ʣ�һά���飡
    if (!A.base)exit(OVERFLOW);
    // ��ӳ�����ĳ���ci,����A.constants[i-1],  i=1,��,dim
    A.constants = (int*)malloc(dim * sizeof(int));
    if (!A.constants) exit(OVERFLOW);
        A.constants[dim - 1] = 1; //���һά��ƫ����Ϊ1
    for (int i = dim - 2; i >= 0; --i)
        A.constants[i] = A.bounds[i + 1] * A.constants[i + 1]; //ÿһά��ƫ����
    return OK;
}

//2����������
Status DestroyArray13(Array& A) {  //��������A
    if (!A.base) return ERROR;
    free(A.base);  A.base = NULL;
    if (!A.bounds) return ERROR;
    free(A.bounds);  A.bounds = NULL;
    if (!A.constants) return ERROR;
    free(A.constants);  A.constants = NULL;
}

//3����Ԫ������������Ե�ַ
Status Locate13(Array A, va_list ap, int& off) {
    //��apָʾ�ĸ��±�ֵ�Ϸ��������Ԫ����A����Ե�ַoff
    int i, ind;
    off = 0;
    for (i = 0; i < A.dim; ++i) {
        ind = va_arg(ap, int); //��һ��ȡ��ά���±�ֵ
        if (ind < 0 || ind >= A.bounds[i]) //��ά���±�ֵ���Ϸ�
            return OVERFLOW;
        off += A.constants[i] * ind;
    }
    return OK;
}

//4��A��Ԫ��ֵ��������e
Status Value13(Array A, ElemType* e, ...) {
    // A �� n ά���飬e ΪԪ�ر�����ָ�룬����� n �±�ֵ��
    // �����±겻���磬�� *e ��ֵΪ��ָ���� A ��Ԫ��ֵ
    va_list ap; // �䳤����������, �� stdarg.h
    int off;
    va_start(ap, e); // �䳤������...�����β� A ֮��ʼ
    Status result;
    if ((result = Locate13(A, ap, off)) == OVERFLOW) // ���� Locate()����ñ䳤������ָ��Ԫ����Ե�ַ off
        return result;
    *e = *(A.base + off); // ���䳤������ָ��Ԫ��ֵ���� *e
    return OK;
}

//5������e��ֵ������ָ����A��Ԫ��
Status Assign13(Array& A, ElemType e,...) {
    //A��nά���飬eΪԪ�ر����������n���±�ֵ��
    //���±겻���磬��e��ֵ������ָ����A��Ԫ��
    va_list ap; //�䳤����������,��stdarg.h 
    int off;
    va_start(ap, e); //�䳤������...�����β�A֮��ʼ
    Status result;
    if ((result = Locate13(A, ap, off)) == OVERFLOW)
        return result;
    *(A.base + off) = e; //��e��ֵ�����䳤������ָ��Ԫ
    return OK;
}

//��ӡ����
//�������������ڵݹ��ӡ����Ԫ��
//void printArrayRecursive(Array A, int* indices, int currentDim) {
//    if (currentDim == A.dim) {
//        int offset = 0;
//        for (int i = 0; i < A.dim; i++) {
//            offset += indices[i] * A.constants[i];
//        }
//        printf("%d ", A.base[offset]);
//        return;
//    }
//
//    for (int i = 0; i < A.bounds[currentDim]; i++) {
//        indices[currentDim] = i;
//        printArrayRecursive(A, indices, currentDim + 1);
//        if (currentDim == A.dim - 1) {
//            printf("\n");
//        }
//    }
//}
//
//// ��ӡ���麯��
//void printArray13(Array A) {
//    if (A.dim < 1 || A.dim > MAX_ARRAY_DIM || !A.base || !A.bounds || !A.constants) {
//        printf("Invalid array.\n");
//        return;
//    }
//
//    int* indices = (int*)malloc(A.dim * sizeof(int));
//    if (!indices) {
//        printf("Memory allocation failed.\n");
//        return;
//    }
//
//    for (int i = 0; i < A.dim; i++) {
//        indices[i] = 0;
//    }
//
//    printArrayRecursive(A, indices, 0);
//
//    free(indices);
//}