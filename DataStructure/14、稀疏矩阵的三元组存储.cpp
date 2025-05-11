#include "结构、常量定义及函数声明.h"

//1、转置矩阵
Status TransposeSMatrix14(TSMatrix M, TSMatrix& T) {
    //  q 指示 T.data 中三元组的序号，p 指示 M.data 中三元组的序号，col 指示 M 的列号
    T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
    if (T.tu) {
        int q = 1;
        for (int col = 1; col <= M.nu; ++col)
            for (int p = 1; p <= M.tu; ++p)
                if (M.data[p].j == col) {            // 进行转置
                    T.data[q].i = M.data[p].j;       // M 的列域值成为其转置矩阵 T 的行域值
                    T.data[q].j = M.data[p].i;       // M 的行域值成为其转置矩阵 T 的行域值
                    T.data[q].e = M.data[p].e;       // 将 M 的非零元值赋给其转置矩阵 T
                    ++q;                             // T.data 中三元组的序号加 1
                } // if ( M.data ) 结束
    }  // if ( T.tu ) 结束
    return OK;
}

//2、快速转置矩阵
void FastTransposeSMatrix14(TSMatrix M, TSMatrix& T) {
    // 用三元组顺序表存储，快速求稀疏矩阵M的转置矩阵 T
    int p, q, col, * num, * cpot;
    num = (int*)malloc((M.nu + 1) * sizeof(int));  // 存M每列(T每行)非零元素个数([0]不用)
    cpot = (int*)malloc((M.nu + 1) * sizeof(int));  // 存T每行下一个非零元素的位置([0]不用)

    T.mu = M.nu;  // T的行数 = M的列数
    T.nu = M.mu;  // T的列数 = M的行数
    T.tu = M.tu;  // T的非零元素个数 = M的非零元素个数

    if (T.tu) {  // T是非零矩阵
        for (col = 1; col <= M.nu; col++)  // 从M的第一列到最后一列
            num[col] = 0;  // 计数器初值设为0

        for (p = 1; p <= M.tu; p++)  // 对于M的每一个非零元素
            ++num[M.data[p].j];  // 根据它所在的列进行统计

        cpot[1] = 1;  // T的第一行的第一个非零元在T.data中的序号为1
        for (col = 2; col <= M.nu; col++)  // 从M（T）的第二列（行）到最后一列（行）
            cpot[col] = cpot[col - 1] + num[col - 1];  // 求T的第col行第一个非零元在T.data中的序号

        for (p = 1; p <= M.tu; p++) {  // 对于M的每一个非零元素
            col = M.data[p].j;  // 将其在M中的列数赋给col
            q = cpot[col];  // q指示M当前的元素在T中的序号
            T.data[q].i = M.data[p].j;  // 将M当前的元素转置赋给T
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            cpot[col]++;  // T第col行的下一个非零元在T.data中的序号比当前元素的序号大1
        }  // for
    }  // if

    free(num);    // 释放num动态存储空间
    free(cpot);   // 释放cpot动态存储空间
}  // FastTransposeSMatrix

//打印稀疏矩阵
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
