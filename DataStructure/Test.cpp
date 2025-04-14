#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int num;        // 节点编号
    int password;   // 节点对应的密码
    struct Node* next;  // 指向下一个节点的指针
} Node;

// 创建单向循环链表
Node* createList(int n, int passwords[]) {
    if (n == 0) return NULL;
    Node* head = NULL, * tail = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->num = i;              // 初始化节点编号
        newNode->password = passwords[i - 1]; // 初始化节点密码
        if (i == 1) {
            head = newNode;
            tail = newNode;
            newNode->next = head;      // 第一个节点，自己指向自己形成循环
        }
        else {
            tail->next = newNode;      // 链接到链表尾部
            tail = newNode;
            tail->next = head;         // 尾部节点指向头节点，形成循环
        }
    }
    return head;
}

// 约瑟夫问题处理函数
void josephus(Node* head, int m) {
    if (!head) return; // 如果链表为空，直接返回
    Node* curr = head;
    Node* prev = NULL;
    // 找到curr的前一个节点prev
    while (prev == NULL || prev->next != curr) {
        prev = (prev == NULL) ? curr : prev->next;
    }
    while (curr->next != curr) { // 当链表中不止一个节点时循环
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;    // 移动curr和prev指针，模拟报数过程
        }
        printf("%d ", curr->num); // 输出当前出列节点的编号
        m = curr->password;       // 更新m为出列节点的密码
        prev->next = curr->next;  // 从链表中移除curr节点
        free(curr);               // 释放curr节点的内存
        curr = prev->next;        // curr指向新的当前节点
    }
    printf("%d\n", curr->num); // 输出最后一个节点的编号
    free(curr);               // 释放最后一个节点的内存
}

int main() {
    int n, m;
    printf("请输入报数上限值m: ");
    scanf("%d", &m);
    printf("请输入总人数n: ");
    scanf("%d", &n);
    int passwords[30];
    printf("请依次输入%d个密码: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &passwords[i]);
    }
    Node* head = createList(n, passwords); // 创建循环链表
    josephus(head, m);                     // 处理约瑟夫问题
    return 0;
}