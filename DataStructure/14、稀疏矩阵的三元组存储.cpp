#include "�ṹ���������弰��������.h"

//1��ת�þ���
Status TransposeSMatrix14(TSMatrix M, TSMatrix& T) {
    //  q ָʾ T.data ����Ԫ�����ţ�p ָʾ M.data ����Ԫ�����ţ�col ָʾ M ���к�
    T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
    if (T.tu) {
        int q = 1;
        for (int col = 1; col <= M.nu; ++col)
            for (int p = 1; p <= M.tu; ++p)
                if (M.data[p].j == col) {            // ����ת��
                    T.data[q].i = M.data[p].j;       // M ������ֵ��Ϊ��ת�þ��� T ������ֵ
                    T.data[q].j = M.data[p].i;       // M ������ֵ��Ϊ��ת�þ��� T ������ֵ
                    T.data[q].e = M.data[p].e;       // �� M �ķ���Ԫֵ������ת�þ��� T
                    ++q;                             // T.data ����Ԫ�����ż� 1
                } // if ( M.data ) ����
    }  // if ( T.tu ) ����
    return OK;
}

//2������ת�þ���
void FastTransposeSMatrix14(TSMatrix M, TSMatrix& T) {
    // ����Ԫ��˳���洢��������ϡ�����M��ת�þ��� T
    int p, q, col, * num, * cpot;
    num = (int*)malloc((M.nu + 1) * sizeof(int));  // ��Mÿ��(Tÿ��)����Ԫ�ظ���([0]����)
    cpot = (int*)malloc((M.nu + 1) * sizeof(int));  // ��Tÿ����һ������Ԫ�ص�λ��([0]����)

    T.mu = M.nu;  // T������ = M������
    T.nu = M.mu;  // T������ = M������
    T.tu = M.tu;  // T�ķ���Ԫ�ظ��� = M�ķ���Ԫ�ظ���

    if (T.tu) {  // T�Ƿ������
        for (col = 1; col <= M.nu; col++)  // ��M�ĵ�һ�е����һ��
            num[col] = 0;  // ��������ֵ��Ϊ0

        for (p = 1; p <= M.tu; p++)  // ����M��ÿһ������Ԫ��
            ++num[M.data[p].j];  // ���������ڵ��н���ͳ��

        cpot[1] = 1;  // T�ĵ�һ�еĵ�һ������Ԫ��T.data�е����Ϊ1
        for (col = 2; col <= M.nu; col++)  // ��M��T���ĵڶ��У��У������һ�У��У�
            cpot[col] = cpot[col - 1] + num[col - 1];  // ��T�ĵ�col�е�һ������Ԫ��T.data�е����

        for (p = 1; p <= M.tu; p++) {  // ����M��ÿһ������Ԫ��
            col = M.data[p].j;  // ������M�е���������col
            q = cpot[col];  // qָʾM��ǰ��Ԫ����T�е����
            T.data[q].i = M.data[p].j;  // ��M��ǰ��Ԫ��ת�ø���T
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            cpot[col]++;  // T��col�е���һ������Ԫ��T.data�е���űȵ�ǰԪ�ص���Ŵ�1
        }  // for
    }  // if

    free(num);    // �ͷ�num��̬�洢�ռ�
    free(cpot);   // �ͷ�cpot��̬�洢�ռ�
}  // FastTransposeSMatrix

//��ӡϡ�����
//void printMatrix14(TSMatrix M) {
//    for (int i = 1; i <= M.nu; i++) {
//        for (int j = 1; j <= M.mu; j++) {
//            int value = 0;
//            for (int k = 0; k < M.tu; k++) {
//                if (i == M.data[k].i && j == M.data[k].j) {
//                    printf("%d ", M.data[k].e);
//                    value = 1;
//                    break;
//                }
//            }
//            if (value == 0)
//                printf("0 ");
//        }
//        printf("\n");
//    }
//}
