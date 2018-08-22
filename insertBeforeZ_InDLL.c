#include<stdio.h>
#include<stdlib.h>

//Insert before Z in Double LinkList

struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
};

void InsertBeforeZ(struct Node* S, int Z, int data)
{
	struct Node* N= (struct Node*)(malloc(sizeof(struct Node)));

	if(N==NULL)
	{
		printf("Unable To Allocate space in memory\n");
		return;
	}

	while(S->data!=Z)
		S=S->next;

	N->data=data;
	N->next=S;
	N->previous=S->previous;
	if(S->previous!=NULL) //if S is first node then this if condition is false
		S->previous->next=N;
	S->previous=N;

}

void printDLL(struct Node* S)
{
	while(S!=NULL)
	{
		printf("node:%d\n",S->data );
		S=S->next;
	}
}

int main()
{
	struct Node S[]={{5,S+1,NULL},
					 {8,S+2,S},
					 {7,S+3,S+1},
					 {15,S+4,S+2},
					 {1,NULL,S+3} };

	InsertBeforeZ(S,5,6);
	printDLL(S);
	return 0;
}