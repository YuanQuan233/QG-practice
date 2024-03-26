#include <stdio.h>
#include <stdlib.h>
#include"head.c"

struct Queue {
    struct Node* front;  // 队列头部
    struct Node* rear;   // 队列尾部
};

// 创建一个空队列
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 判断队列是否为空
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// 入队操作
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

// 出队操作
void* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("队列为空\n");
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
    // 创建一个整型队列
    struct Queue* intQueue = createQueue();

    // 向队列中添加一些整型数据
    int i;
    for (i = 1; i <= 5; i++) {
        int* data = (int*)malloc(sizeof(int));
        *data = i;
        enqueue(intQueue, data);
    }

    // 出队并打印整型队列中的数据
    printf("出队元素：");
    while (!isEmpty(intQueue)) {
        int* data = (int*)dequeue(intQueue);
        printf("%d ", *data);
        free(data);
    }
    printf("\n");

    // 创建一个字符串队列
    struct Queue* stringQueue = createQueue();

    // 向队列中添加一些字符串数据
    char* strs[] = {"apple", "banana", "orange", "grape", "melon"};
    for (i = 0; i < 5; i++) {
        char* data = strs[i];
        enqueue(stringQueue, data);
    }

    // 出队并打印字符串队列中的数据
    printf("出队元素：");
    while (!isEmpty(stringQueue)) {
        char* data = (char*)dequeue(stringQueue);
        printf("%s ", data);
    }
    printf("\n");

    return 0;
}