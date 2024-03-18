#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义结构体
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// 在链表头部插入元素
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// 删除链表头部元素
void deleteFromBeginning() {
    if (head == NULL) {
        printf("链表为空，无法删除\n");
    }
    else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// 显示链表元素
void displayList() {
    struct Node* current = head;
    if (current == NULL) {
        printf("链表为空\n");
    }
    else {
        printf("链表元素：");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n单向链表操作菜单\n");
        printf("1. 插入元素\n");
        printf("2. 删除元素\n");
        printf("3. 显示链表\n");
        printf("4. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入要插入的值：");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            deleteFromBeginning();
            break;
        case 3:
            displayList();
            break;
        case 4:
            printf("程序结束\n");
            exit(0);
        default:
            printf("无效选择\n");
        }
    }

    return 0;
}