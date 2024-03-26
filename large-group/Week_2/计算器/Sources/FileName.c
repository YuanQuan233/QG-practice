#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"head.c"

void initStack(Node** top) {               //��ʼ����ջ
    *top = NULL;
}

void push(Node** top, char data) {                        //��ջ
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char getop(Node* top) {                         //��ȡջ��Ԫ��
    if (top == NULL) {
        printf("ջ�ǿյģ�����\n");
        exit(0);
    }
    return top->data;
}

char pull(Node** top) {                        //��ջ
    if (*top == NULL) {
        printf("ջ�ǿյģ�����\n");
        exit(0);
    }
    Node* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

int precedence(char op) {                   //�ж����ȼ�
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Node* stack;
    initStack(&stack);

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        else if (infix[i] == ')') {
            while (getop(stack) != '(') {
                postfix[j++] = pull(&stack);
            }
            pull(&stack); // ����������
        }
        else {
            while (stack != NULL && precedence(infix[i]) <= precedence(getop(stack))) {
                postfix[j++] = pull(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }

    while (stack != NULL) {
        postfix[j++] = pull(&stack);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {                   //����
    Node* stack;
    initStack(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        }
        else {
            int operand2 = pull(&stack);
            int operand1 = pull(&stack);
            switch (postfix[i]) {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            }
        }
        i++;
    }

    return pull(&stack);
}

int main() {
    char infix[100];
    char postfix[100];

    printf("������Ҫ���������������ʽ�����������ȼ�����");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("ת��Ϊ��׺���ʽ��%s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("������Ϊ��%d\n", result);

    return 0;
}