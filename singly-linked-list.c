#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node* next;
} Node;

// Add data to the front of the singly linked list
void AddData(Node* head, int data) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;
	head->next = node;
	return;
}

// Remove data from singly linked list
void RemoveData(Node* head, int data) {
	if(head->next == NULL) {
		printf("List is empty\n");
		return;
	}
	Node* cur = head->next;
	Node* prev;
	while(cur != NULL) {
		if(cur->data == data) {
			if(cur == head->next) {
				head->next = cur->next;
			}
			else {
				prev->next = cur->next;
			}
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	printf("No data in list\n");
	return;
}

// Print all data from singly linked list
void PrintAll(Node* head) {
	if(head->next == NULL) {
		printf("List is empty\n");
		return;
	}
	Node* cur = head->next;
	int count = 0;
	while(cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
		count++;
	}
	printf("| count = %d\n", count);
	return;
}

// Free all data from sinlgy linked list
void FreeAll(Node* head) {
	Node* cur = head->next;
	Node* next;
	while(cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	head->next = NULL;
	// Q. 모든 노드 free 처리했는데 왜 각 포인터는 그대로 연결되어 있는가? 모든 노드 free 처리한 뒤, 따로 head->next = NULL 하지 않고 AddData 해서 PrintAll 했을 때 왜 넣지도 않은 값들이 주루룩 뜨는지?
	// A. 각 메모리들을 free 처리해서 각 포인터가 가리키는 주소는 달라졌지만 연결 자체는 그대로?
	return;
}

int main(void)
{
	Node* head = (Node*) malloc(sizeof(Node));
	head->next = NULL;
	// Node* head = NULL;
	// Q. head에 Node 별도 할당하지 않고 그냥 Node* 상태로만 넘겨서 처리할 경우에 AddData 함수 내에서 추가한 데이터가 왜 함수 밖에서는 적용되지 않을까?
	// A. 함수 내 지역변수라 그냥 사라진다? but 함수 내에서 동적할당하여 head가 해당 메모리 가리키도록 한 것인데,, 동적할당한 메모리는 함수 밖으로 나와도 유지되지 않나? 근데 왜 그냥 Node* head를 넘겼을 때는 안되는데 Node* head에 동적할당하여 head->next에 연결했을 때는 되는지,,?
	
	PrintAll(head);
	AddData(head, 0);
	AddData(head, 2);
	AddData(head, 4);
	AddData(head, 6);
	AddData(head, 8);
	PrintAll(head);
	RemoveData(head, 6);
	RemoveData(head, 5);
	RemoveData(head, 0);
	PrintAll(head);
	FreeAll(head);
	PrintAll(head);
	AddData(head, 10);
	AddData(head, 12);
	PrintAll(head);
	RemoveData(head, 10);
	RemoveData(head, 12);
	RemoveData(head, 14);
	PrintAll(head);

	return 0;
}