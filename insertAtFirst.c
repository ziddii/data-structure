#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int  data;
	struct Node* next;	
};

void InsertAtFirst(struct Node* S, int data)
{
	struct Node* N= (struct Node*)(malloc(sizeof(struct Node)));
	
	if(N==NULL)
	{
		printf("Failed to Allocate memory");
		return;
	}
	else
	{
		N->data=data;
		N->next=NULL;

		if(S==NULL)
		{
			S=N;
		}
		else
		{
			N->next=S;
			S=N;
		}
	}
}
