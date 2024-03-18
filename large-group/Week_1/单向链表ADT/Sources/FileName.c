#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����ṹ��
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// ������ͷ������Ԫ��
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// ɾ������ͷ��Ԫ��
void deleteFromBeginning() {
    if (head == NULL) {
        printf("����Ϊ�գ��޷�ɾ��\n");
    }
    else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
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
        printf("\n������������˵�\n");
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
            insertAtBeginning(value);
            break;
        case 2:
            deleteFromBeginning();
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