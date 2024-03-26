#include<stdio.h>
#include<stdlib.h>
#include"Head.c"

void push(Node** top, int data) {                   //��ջ
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("������󣡣���\n");
		exit(0);
	}
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
	printf("����ɹ���\n\n");
}

int getop(Node* top) {                       //��ȡջ��Ԫ��
	if (top == NULL) {
		printf("ջ�ǿյģ�");
		exit(0);
	}
	return top->data;
}

int pull(Node** top) {                        //��ջ
	if (*top == NULL) {
		printf("ջ�ǿյģ�");
		exit(0);
	}
	Node* temp = *top;
	int data = temp->data;
	*top = (*top)->next;
	free(temp);
	return data;
}

int main() {
	Node* top;
	top = NULL;

	push(&top, 23333);
	printf("ջ��Ԫ��Ϊ��%d\n\n", getop(top));

	pull(&top);
	printf("ջ�е�Ԫ�ر��ͷ��ˡ�\n\n");

	return 0;
}
