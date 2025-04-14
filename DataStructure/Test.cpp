#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int num;        // �ڵ���
    int password;   // �ڵ��Ӧ������
    struct Node* next;  // ָ����һ���ڵ��ָ��
} Node;

// ��������ѭ������
Node* createList(int n, int passwords[]) {
    if (n == 0) return NULL;
    Node* head = NULL, * tail = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->num = i;              // ��ʼ���ڵ���
        newNode->password = passwords[i - 1]; // ��ʼ���ڵ�����
        if (i == 1) {
            head = newNode;
            tail = newNode;
            newNode->next = head;      // ��һ���ڵ㣬�Լ�ָ���Լ��γ�ѭ��
        }
        else {
            tail->next = newNode;      // ���ӵ�����β��
            tail = newNode;
            tail->next = head;         // β���ڵ�ָ��ͷ�ڵ㣬�γ�ѭ��
        }
    }
    return head;
}

// Լɪ�����⴦����
void josephus(Node* head, int m) {
    if (!head) return; // �������Ϊ�գ�ֱ�ӷ���
    Node* curr = head;
    Node* prev = NULL;
    // �ҵ�curr��ǰһ���ڵ�prev
    while (prev == NULL || prev->next != curr) {
        prev = (prev == NULL) ? curr : prev->next;
    }
    while (curr->next != curr) { // �������в�ֹһ���ڵ�ʱѭ��
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;    // �ƶ�curr��prevָ�룬ģ�ⱨ������
        }
        printf("%d ", curr->num); // �����ǰ���нڵ�ı��
        m = curr->password;       // ����mΪ���нڵ������
        prev->next = curr->next;  // ���������Ƴ�curr�ڵ�
        free(curr);               // �ͷ�curr�ڵ���ڴ�
        curr = prev->next;        // currָ���µĵ�ǰ�ڵ�
    }
    printf("%d\n", curr->num); // ������һ���ڵ�ı��
    free(curr);               // �ͷ����һ���ڵ���ڴ�
}

int main() {
    int n, m;
    printf("�����뱨������ֵm: ");
    scanf("%d", &m);
    printf("������������n: ");
    scanf("%d", &n);
    int passwords[30];
    printf("����������%d������: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &passwords[i]);
    }
    Node* head = createList(n, passwords); // ����ѭ������
    josephus(head, m);                     // ����Լɪ������
    return 0;
}