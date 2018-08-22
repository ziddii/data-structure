#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int  data;
	struct Node* next;	
};

void InsertAfterX(int X, int Y, struct node* S)
{
	struct Node* N= (struct Node*)(malloc(sizeof(struct Node)));
	if(N==NULL)
	{
		printf("Failed to Allocate memory");
		return;
	}
	else
	{
		N->data=Y;

	 	while(S->data!=X)
	 		S=S->next;
	 	
	 	N->next= S->next;
	 	S->next= N;

	}


}
