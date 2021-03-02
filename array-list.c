#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef struct _ArrayList {
	int data[MAX_LIST_SIZE];
	int count;
} ArrayList;

// Add data to index in array list
void AddData(ArrayList* list, int data, int index) {
	if(list->count >= MAX_LIST_SIZE) {	// overflow check
		printf("List is full\n");
		return;
	}
	if(list->count < index) {	// index validation check - Empty indexs not allowed in the middle of the arraylist
		printf("Wrong index\n");
		return;
	}
	for(int i = list->count - 1; i >= index; i--) {
		list->data[i + 1] = list->data[i];
	}
	list->data[index] = data;
	list->count++;
	return;
}

// Remove data from index from array list
void RemoveData(ArrayList* list, int index) {
	if(list->count <= 0) {	// underflow check
		printf("List is empty\n");
		return;
	}
	if(list->count <= index) {	// index validation check
		printf("Wrong index\n");
		return;
	}
	for(int i = index; i < list->count - 1; i++) {
		list->data[i] = list->data[i + 1];
	}
	list->count--;
	return;
}

// Print all data from array list
void PrintAll(ArrayList* list) {
	if(list->count <= 0) {
		printf("List is empty\n");
		return;
	}
	for(int i = 0; i < list->count; i++) {
		printf("%d ", list->data[i]);
	}
	printf("| count = %d\n", list->count);
	return;
}

int main(void)
{
	ArrayList list;
	list.count = 0;
	
	PrintAll(&list);
	AddData(&list, 0, 0);
	AddData(&list, 2, 0);
	AddData(&list, 4, 0);
	AddData(&list, 6, 0);
	AddData(&list, 8, 0);
	PrintAll(&list);
	AddData(&list, 12, 6);
	AddData(&list, 10, 5);
	PrintAll(&list);
	RemoveData(&list, 6);
	RemoveData(&list, 5);
	RemoveData(&list, 0);
	RemoveData(&list, 0);
	RemoveData(&list, 0);
	PrintAll(&list);
	RemoveData(&list, 0);
	RemoveData(&list, 0);
	RemoveData(&list, 0);
	PrintAll(&list);
	
	return 0;
}