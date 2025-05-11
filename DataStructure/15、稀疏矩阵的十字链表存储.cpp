#include "�ṹ���������弰��������.h"

//1����ʼ��ϡ�����
Status CreateSMatrix_OL15(CrossList& M) {
    // �ͷ�ԭ���ڴ棨�����ڣ�
    if (M.rhead) {
        free(M.rhead);
        M.rhead = nullptr;
    }
    if (M.chead) {
        free(M.chead);
        M.chead = nullptr;
    }
    // �������ά��
    int m, n, t;
    printf("����������������������Ԫ�������ÿո�ָ���: ");
    if (scanf("%d %d %d", &m, &n, &t) != 3) {  // ���������ʽ�ַ���
        printf("�����ʽ����\n");
        return ERROR;
    }
    M.mu = m;
    M.nu = n;
    M.tu = t;

    // ������/��ͷָ�����飨�±�1~m/n��
    M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink));  // �����1��λ�ø��±�0����ʹ�ã�
    M.chead = (OLink*)malloc((n + 1) * sizeof(OLink));
    if (!M.rhead || !M.chead) {
        printf("�ڴ����ʧ�ܣ�\n");
        return OVERFLOW;
    }

    // ��ʼ��ͷָ��Ϊnullptr
    for (int k = 1; k <= m; ++k) M.rhead[k] = nullptr;
    for (int k = 1; k <= n; ++k) M.chead[k] = nullptr;

    // ���벢����Ԫ��
    int i, j, e;
    printf("������Ԫ�ص��кš��кš�ֵ����0 0 0�������룩:\n");
    while (true) {
        printf("> ");
        if (scanf("%d %d %d", &i, &j, &e) != 3) {  // �ϸ���������Ч��
            printf("�����ʽ�����������룡\n");
            while (getchar() != '\n');  // ������뻺����
            continue;
        }

        if (i == 0 && j == 0 && e == 0) break;  // ��������

        // ������к���Ч��
        if (i < 1 || i > m || j < 1 || j > n) {
            printf("���кų�����Χ��1~%d�У�1~%d�У���������ǰԪ��\n", m, n);
            continue;
        }

        // �����½ڵ�
        OLNode* p = (OLNode*)malloc(sizeof(OLNode));
        if (!p) return OVERFLOW;
        p->i = i;
        p->j = j;
        p->e = e;
        p->right = nullptr;
        p->down = nullptr;

        // �������������к�����
        OLink* rowHead = &M.rhead[i];  // ��ͷָ���ָ�루����ֱ���޸�ͷָ�룩
        if (!*rowHead || (*rowHead)->j > j) {  // ͷ�ڵ�Ϊ�� �� ��ǰͷ�ڵ��кŸ���
            p->right = *rowHead;
            *rowHead = p;
        }
        else {
            OLink q = *rowHead;
            while (q->right && q->right->j < j)  // Ѱ�Ҳ���λ��
                q = q->right;
            p->right = q->right;
            q->right = p;
        }

        // �������������к�����
        OLink* colHead = &M.chead[j];  // ��ͷָ���ָ��
        if (!*colHead || (*colHead)->i > i) {  // ͷ�ڵ�Ϊ�� �� ��ǰͷ�ڵ��кŸ���
            p->down = *colHead;
            *colHead = p;
        }
        else {
            OLink q = *colHead;
            while (q->down && q->down->i < i)  // Ѱ�Ҳ���λ��
                q = q->down;
            p->down = q->down;
            q->down = p;
        }
    }
    return OK;
}

//��ӡϡ�����
void printMatrix15(CrossList M) {
	printf("ϡ������ʮ������洢�ṹ��\n");
	for (int i = 1; i <= M.mu; ++i) {
		OLink p = M.rhead[i];
		while (p) {
			printf("(%d, %d, %d) ", p->i, p->j, p->e);
			p = p->right;
		}
		printf("\n");
	}
}