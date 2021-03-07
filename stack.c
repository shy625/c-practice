#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 999999999

typedef struct _Node {
	int data;
	struct _Node* next;
} Node;

typedef struct _Stack {
	Node* top;
} Stack;

// Check whether stack is empty or not
bool isEmpty(Stack* stack) {
	if(stack->top == NULL) return true;
	else return false;
}

// Push data to top of the stack
void Push(Stack* stack, int data) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

// Pop data from top of the stack
void Pop(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty\n");
		return;
	}
	Node* cur = stack->top;
	stack->top = cur->next;
	free(cur);
	return;
}

// Get data from top of the stack
int GetTop(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty\n");
		return -INF;
	}
	return stack->top->data;
}

// Printf all data in stack
void PrintStack(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty\n");
		return;
	}
	Node* cur = stack->top;
	printf("TOP\n");
	while(cur != NULL) {
		printf("| %d\n", cur->data);
		cur = cur->next;
	}
	return;
}

int main(void)
{
	Stack stack;
	stack.top = NULL;
	
	Pop(&stack);
	Push(&stack, 0);
	Push(&stack, 2);
	Push(&stack, 4);
	PrintStack(&stack);
	printf("TOP = %d\n", GetTop(&stack));
	Pop(&stack);
	Pop(&stack);
	Push(&stack, 6);
	PrintStack(&stack);
	printf("TOP = %d\n", GetTop(&stack));
	Pop(&stack);
	Pop(&stack);
	printf("TOP = %d\n", GetTop(&stack));

	return 0;
}