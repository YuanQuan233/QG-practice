#include <stdio.h>
#include <stdlib.h>
#include"head.c"

struct Queue {
    struct Node* front;  // ����ͷ��
    struct Node* rear;   // ����β��
};

// ����һ���ն���
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// ��Ӳ���
void enqueue(struct Queue* queue, void* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
}

// ���Ӳ���
void* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("����Ϊ��\n");
        return NULL;
    } else {
        struct Node* temp = queue->front;
        void* data = temp->data;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

int main() {
    // ����һ�����Ͷ���
    struct Queue* intQueue = createQueue();

    // ����������һЩ��������
    int i;
    for (i = 1; i <= 5; i++) {
        int* data = (int*)malloc(sizeof(int));
        *data = i;
        enqueue(intQueue, data);
    }

    // ���Ӳ���ӡ���Ͷ����е�����
    printf("����Ԫ�أ�");
    while (!isEmpty(intQueue)) {
        int* data = (int*)dequeue(intQueue);
        printf("%d ", *data);
        free(data);
    }
    printf("\n");

    // ����һ���ַ�������
    struct Queue* stringQueue = createQueue();

    // ����������һЩ�ַ�������
    char* strs[] = {"apple", "banana", "orange", "grape", "melon"};
    for (i = 0; i < 5; i++) {
        char* data = strs[i];
        enqueue(stringQueue, data);
    }

    // ���Ӳ���ӡ�ַ��������е�����
    printf("����Ԫ�أ�");
    while (!isEmpty(stringQueue)) {
        char* data = (char*)dequeue(stringQueue);
        printf("%s ", data);
    }
    printf("\n");

    return 0;
}