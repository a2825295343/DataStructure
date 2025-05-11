#include "结构、常量定义及函数声明.h"

//1、初始化稀疏矩阵
Status CreateSMatrix_OL15(CrossList& M) {
    // 释放原有内存（若存在）
    if (M.rhead) {
        free(M.rhead);
        M.rhead = nullptr;
    }
    if (M.chead) {
        free(M.chead);
        M.chead = nullptr;
    }
    // 输入矩阵维度
    int m, n, t;
    printf("请输入行数、列数、非零元个数（用空格分隔）: ");
    if (scanf("%d %d %d", &m, &n, &t) != 3) {  // 修正输入格式字符串
        printf("输入格式错误！\n");
        return ERROR;
    }
    M.mu = m;
    M.nu = n;
    M.tu = t;

    // 分配行/列头指针数组（下标1~m/n）
    M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink));  // 多分配1个位置给下标0（不使用）
    M.chead = (OLink*)malloc((n + 1) * sizeof(OLink));
    if (!M.rhead || !M.chead) {
        printf("内存分配失败！\n");
        return OVERFLOW;
    }

    // 初始化头指针为nullptr
    for (int k = 1; k <= m; ++k) M.rhead[k] = nullptr;
    for (int k = 1; k <= n; ++k) M.chead[k] = nullptr;

    // 输入并插入元素
    int i, j, e;
    printf("请输入元素的行号、列号、值（以0 0 0结束输入）:\n");
    while (true) {
        printf("> ");
        if (scanf("%d %d %d", &i, &j, &e) != 3) {  // 严格检查输入有效性
            printf("输入格式错误，重新输入！\n");
            while (getchar() != '\n');  // 清空输入缓冲区
            continue;
        }

        if (i == 0 && j == 0 && e == 0) break;  // 结束条件

        // 检查行列号有效性
        if (i < 1 || i > m || j < 1 || j > n) {
            printf("行列号超出范围（1~%d行，1~%d列），跳过当前元素\n", m, n);
            continue;
        }

        // 创建新节点
        OLNode* p = (OLNode*)malloc(sizeof(OLNode));
        if (!p) return OVERFLOW;
        p->i = i;
        p->j = j;
        p->e = e;
        p->right = nullptr;
        p->down = nullptr;

        // 插入行链表（按列号升序）
        OLink* rowHead = &M.rhead[i];  // 行头指针的指针（便于直接修改头指针）
        if (!*rowHead || (*rowHead)->j > j) {  // 头节点为空 或 当前头节点列号更大
            p->right = *rowHead;
            *rowHead = p;
        }
        else {
            OLink q = *rowHead;
            while (q->right && q->right->j < j)  // 寻找插入位置
                q = q->right;
            p->right = q->right;
            q->right = p;
        }

        // 插入列链表（按行号升序）
        OLink* colHead = &M.chead[j];  // 列头指针的指针
        if (!*colHead || (*colHead)->i > i) {  // 头节点为空 或 当前头节点行号更大
            p->down = *colHead;
            *colHead = p;
        }
        else {
            OLink q = *colHead;
            while (q->down && q->down->i < i)  // 寻找插入位置
                q = q->down;
            p->down = q->down;
            q->down = p;
        }
    }
    return OK;
}

//打印稀疏矩阵
void printMatrix15(CrossList M) {
	printf("稀疏矩阵的十字链表存储结构：\n");
	for (int i = 1; i <= M.mu; ++i) {
		OLink p = M.rhead[i];
		while (p) {
			printf("(%d, %d, %d) ", p->i, p->j, p->e);
			p = p->right;
		}
		printf("\n");
	}
}