#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
};

void deleteAfterCurrent(struct Node* S)
{
	struct Node* temp= S->next;
	S-next=S->next->next;
	S->next->previous=S;
	free(temp);
}
