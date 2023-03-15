#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// 스택 초기화 함수
void initStack(Stack* stack) {
    stack->top = NULL;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 스택의 top에 데이터 추가하는 함수
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    newNode->prev = NULL;
    
    if (!isEmpty(stack)) {
        stack->top->prev = newNode;
    }
    
    stack->top = newNode;
}

// 스택의 top에서 데이터 제거하는 함수
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    
    Node* popped = stack->top;
    int data = popped->data;
    stack->top = popped->next;
    
    if (!isEmpty(stack)) {
        stack->top->prev = NULL;
    }
    
    free(popped);
    return data;
}

// 스택의 top에 있는 데이터 반환하는 함수
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    
    return stack->top->data;
}

// 양방향 연결 리스트로 구현된 스택 2개를 이용하여 퀵 소트 구현
void quickSort(Stack* stack, int left, int right) {
    if (left >= right) {
        return;
    }
    
    // pivot 설정
    int pivot = peek(stack);
    
    Stack leftStack, rightStack;
    initStack(&leftStack);
    initStack(&rightStack);
    
    // pivot을 제외한 나머지 원소들을 leftStack, rightStack에 나눠 담음
    Node* curr = stack->top->next;
    while (curr != NULL) {
        int data = pop(stack);
        if (data <= pivot) {
            push(&leftStack, data);
        } else {
            push(&rightStack, data);
        }
        curr = curr->next;
    }
    
    // leftStack, rightStack 각각을 재귀적으로 정렬
    quickSort(&leftStack, left, leftStack.top->data);
    quickSort(&rightStack, rightStack.top->data, right);
    
    // leftStack에 있는 원소들을 stack에 넣음
    while (!isEmpty(&leftStack)) {
        push(stack, pop(&leftStack));
    }
    
    // pivot을 stack에 넣음
    push(stack, pivot);
    
    // rightStack에 있는 원소들을 stack에 넣음
    while (!isEmpty(&rightStack)) {
        push(stack, pop(&rightStack));
    }
}
