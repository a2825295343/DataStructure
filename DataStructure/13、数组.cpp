#include "结构、常量定义及函数声明.h"

//1、初始化数组
Status InitArray13(Array& A, int dim,...) {
    //若维数dim和各维长度合法，则构造相应的数组A
    if (dim<1 || dim>MAX_ARRAY_DIM) return ERROR;
    A.dim = dim;
    A.bounds = (int*)malloc(dim * sizeof(int));
    if (!A.bounds) exit(OVERFLOW);
        //若各维长度合法,存入A.bounds,求元素总数elemtotal
        int elemtotal = 1;
		va_list ap; //定义变长参数表ap
        va_start(ap, dim); //变长参数“...”从形参dim之后开始
    //ap为va_list类型，是存放变长参数表信息的数组
    for (int i = 0; i < dim; ++i) {
        A.bounds[i] = va_arg(ap, int); //逐一将变长参数赋给A.bounds[i]，//A.bounds数组中，存放的是各维的大小，
        if (A.bounds[i] < 0) return UNDERFLOW; //在math.h中定义为4
        else elemtotal *= A.bounds[i]; //数组元素总数=各维长度之乘积
    }
    va_end(ap); //结束提取变长参数
    A.base = (ElemType*)malloc(elemtotal * sizeof(ElemType)); //动态分配数组存储空间
    //以下解决如何按“多维”的逻辑角度定位元素的问题。也就是说，对于多维数组的任意下标（在有效范围内）的元素，转换到“一维”空间后，其下标应该是什么。这个体现了“多维数组”的存储本质：一维数组！
    if (!A.base)exit(OVERFLOW);
    // 求映像函数的常数ci,存入A.constants[i-1],  i=1,…,dim
    A.constants = (int*)malloc(dim * sizeof(int));
    if (!A.constants) exit(OVERFLOW);
        A.constants[dim - 1] = 1; //最后一维的偏移量为1
    for (int i = dim - 2; i >= 0; --i)
        A.constants[i] = A.bounds[i + 1] * A.constants[i + 1]; //每一维的偏移量
    return OK;
}

//2、销毁数组
Status DestroyArray13(Array& A) {  //销毁数组A
    if (!A.base) return ERROR;
    free(A.base);  A.base = NULL;
    if (!A.bounds) return ERROR;
    free(A.bounds);  A.bounds = NULL;
    if (!A.constants) return ERROR;
    free(A.constants);  A.constants = NULL;
}

//3、求元素在数组中相对地址
Status Locate13(Array A, va_list ap, int& off) {
    //若ap指示的各下标值合法，求出该元素在A中相对地址off
    int i, ind;
    off = 0;
    for (i = 0; i < A.dim; ++i) {
        ind = va_arg(ap, int); //逐一读取各维的下标值
        if (ind < 0 || ind >= A.bounds[i]) //各维的下标值不合法
            return OVERFLOW;
        off += A.constants[i] * ind;
    }
    return OK;
}

//4、A的元素值赋给变量e
Status Value13(Array A, ElemType* e, ...) {
    // A 是 n 维数组，e 为元素变量的指针，随后是 n 下标值。
    // 若各下标不超界，则 *e 赋值为所指定的 A 的元素值
    va_list ap; // 变长参数表类型, 在 stdarg.h
    int off;
    va_start(ap, e); // 变长参数“...”从形参 A 之后开始
    Status result;
    if ((result = Locate13(A, ap, off)) == OVERFLOW) // 调用 Locate()，求得变长参数所指单元的相对地址 off
        return result;
    *e = *(A.base + off); // 将变长参数所指单元的值赋给 *e
    return OK;
}

//5、变量e的值赋给所指定的A的元素
Status Assign13(Array& A, ElemType e,...) {
    //A是n维数组，e为元素变量，随后是n个下标值。
    //若下标不超界，则将e的值赋给所指定的A的元素
    va_list ap; //变长参数表类型,在stdarg.h 
    int off;
    va_start(ap, e); //变长参数“...”从形参A之后开始
    Status result;
    if ((result = Locate13(A, ap, off)) == OVERFLOW)
        return result;
    *(A.base + off) = e; //将e的值赋给变长参数所指单元
    return OK;
}

//打印数组
//辅助函数，用于递归打印数组元素
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
//// 打印数组函数
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