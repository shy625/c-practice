#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* prev;
	struct _Node* next;
} Node;

// Add data to the front of the doubly linked list
void AddData(Node* head, Node* tail, int data) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
	node->prev = head;
	return;
}

// Remove data from doubly linked list
void RemoveData(Node* head, Node* tail, int data) {
	if(head->next == tail) {	// underflow check
		printf("List is empty\n");
		return;
	}
	Node* cur = head->next;
	while(cur != tail) {
		if(cur->data == data) {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
			return;
		}
		cur = cur->next;
	}
	printf("No data in list\n");
	return;
}

// Print all data from doubly linked list
void PrintAll(Node* head, Node* tail) {
	if(head->next == tail) {	// underflow check
		printf("List is empty\n");
		return;
	}
	Node* cur = head->next;
	int count = 0;
	while(cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
		count++;
	}
	printf("| count = %d\n", count);
	return;
}

// Free all data from doubly linked list
void FreeAll(Node* head, Node* tail) {
	Node* cur = head->next;
	Node* next;
	while(cur != tail) {	// free all nodes
		next = cur->next;
		free(cur);
		cur = next;
	}
	// initialize the list
	head->next = tail;
	tail->prev = head;
	return;
}

int main(void)
{
	Node* head = (Node*) malloc(sizeof(Node));
	Node* tail = (Node*) malloc(sizeof(Node));
	
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
	
	PrintAll(head, tail);
	AddData(head, tail, 0);
	AddData(head, tail, 2);
	AddData(head, tail, 4);
	AddData(head, tail, 6);
	AddData(head, tail, 8);
	PrintAll(head, tail);
	RemoveData(head, tail, 6);
	RemoveData(head, tail, 5);
	RemoveData(head, tail, 0);
	PrintAll(head, tail);
	FreeAll(head, tail);
	PrintAll(head, tail);
	AddData(head, tail, 10);
	AddData(head, tail, 12);
	PrintAll(head, tail);
	RemoveData(head, tail, 10);
	RemoveData(head, tail, 12);
	RemoveData(head, tail, 14);
	PrintAll(head, tail);
	
	return 0;
}