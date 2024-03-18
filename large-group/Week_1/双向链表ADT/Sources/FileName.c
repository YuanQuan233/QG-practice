#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��������
struct Node {
    int data;
    struct Node* prev;  // ָ��ǰһ���ڵ��ָ��
    struct Node* next;  // ָ���һ���ڵ��ָ��
};

struct Node* head = NULL;
struct Node* tail = NULL;

// ������β������Ԫ��
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

// ɾ������β��Ԫ��
void deleteFromEnd() {
    if (head == NULL) {
        printf("����Ϊ�գ��޷�ɾ��\n");
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

// ��ʾ����Ԫ��
void displayList() {
    struct Node* current = head;
    if (current == NULL) {
        printf("����Ϊ��\n");
    }
    else {
        printf("����Ԫ�أ�");
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
        printf("\n˫����������˵�\n");
        printf("1. ����Ԫ��\n");
        printf("2. ɾ��Ԫ��\n");
        printf("3. ��ʾ����\n");
        printf("4. �˳�\n");
        printf("��ѡ�������");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("������Ҫ�����ֵ��");
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
            printf("�������\n");
            exit(0);
        default:
            printf("��Чѡ��\n");
        }
    }

    return 0;
}