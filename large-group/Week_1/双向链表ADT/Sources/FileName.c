#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义链表
struct Node {
    int data;
    struct Node* prev;  // 指向前一个节点的指针
    struct Node* next;  // 指向后一个节点的指针
};

struct Node* head = NULL;
struct Node* tail = NULL;

// 在链表尾部插入元素
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
        newNode->prev = NULL;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// 删除链表尾部元素
void deleteFromEnd() {
    if (head == NULL) {
        printf("链表为空，无法删除\n");
    }
    else {
        if (head == tail) {
            free(head);
            head = tail = NULL;
        }
        else {
            struct Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
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
        printf("\n双向链表操作菜单\n");
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
            insertAtEnd(value);
            break;
        case 2:
            deleteFromEnd();
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