#include<stdio.h>
#include<stdlib.h>
#include"Head.c"

void push(Node** top, int data) {                   //入栈
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("储存错误！！！\n");
		exit(0);
	}
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
	printf("放入成功！\n\n");
}

int getop(Node* top) {                       //获取栈顶元素
	if (top == NULL) {
		printf("栈是空的！");
		exit(0);
	}
	return top->data;
}

int pull(Node** top) {                        //出栈
	if (*top == NULL) {
		printf("栈是空的！");
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
	printf("栈顶元素为：%d\n\n", getop(top));

	pull(&top);
	printf("栈中的元素被释放了。\n\n");

	return 0;
}
