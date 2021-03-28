// /*
// queue as a linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 999999999

typedef struct _Node {
	int data;
	struct _Node* next;
} Node;

typedef struct _Queue {
	Node* front;
	Node* rear;
} Queue;


bool isEmpty(Queue* q) {
	if(q->front == NULL) return true;
	return false;
}

void EnQ(Queue* q, int data) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if(isEmpty(q)) {
		q->front = node;
		q->rear = node;
	} else {
		q->rear->next = node;
		q->rear = node;
	}
	return;
}

void DeQ(Queue* q) {
	if(isEmpty(q)) {
		printf("Queue is empty\n");
		return;
	}
	Node* cur = q->front;
	q->front = cur->next;
	free(cur);
	return;
}


int Peek(Queue* q) {
	if(isEmpty(q)) {
		printf("Queue is empty\n");
		return -INF;
	}
	return q->front->data;
}

void PrintQ(Queue* q) {
	if(isEmpty(q)) {
		printf("Queue is empty\n");
		return;
	}
	Node* cur = q->front;
	printf("FRONT | ");
	while(cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("| REAR\n");
	return;
}

int main(void)
{
	Queue q;
	q.front = NULL;
	q.rear = NULL;
	
	Peek(&q);
	DeQ(&q);
	EnQ(&q, 10);
	EnQ(&q, 20);
	EnQ(&q, 30);
	PrintQ(&q);
	printf("FRONT = %d\n", Peek(&q));
	DeQ(&q);
	DeQ(&q);
	EnQ(&q, 40);
	PrintQ(&q);
	printf("///FRONT = %d\n", Peek(&q));
	DeQ(&q);
	PrintQ(&q);
	DeQ(&q);
	EnQ(&q, 50);
	printf("FRONT = %d\n", Peek(&q));
	DeQ(&q);
	printf("FRONT = %d\n", Peek(&q));
	PrintQ(&q);
	
	return 0;
}
// */