#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	Node* next;
};

void deleteAfterX(struct Node* S, int X)
{
	while(S->data!=X)
		S=S->next;
	struct Node* P=S->next;
	S->next=S->next->next;
	free(P);
}

int main()
{

	return 0;
}