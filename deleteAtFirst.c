#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	Node* next;
};

void deleteAtFirst(struct Node* S)
{
	struct Node* P=S;
	S=S->next;
	free(P);
}

int main()
{

	return 0;
}