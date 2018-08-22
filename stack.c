#include<stdio.h>

//TOP is -1 when stack is empty 
//TOP is size-1 when stack is full

typedef int DATA;

void push(DATA Stack[], int size, int* TOP, DATA x)
{
	if(*TOP==size-1)
		printf("Error:Overflow: Stack is full");
	else
		Stack[++*TOP]=x;
	return;
}

DATA pop(DATA Stack[], int* TOP)
{
	if(*TOP==-1)
		printf("Error:Underflow: Stack is empty");
	else
		return Stack[(*TOP)--];
	return 0;
}


int main()
{
	DATA Stack[5]={1,2};
	int size=5;
	int TOP=1;

	push(Stack,size,&TOP,5);
	push(Stack,size,&TOP,7);
	push(Stack,size,&TOP,6);
	printf(" poped:%d ",pop(Stack,&TOP));
	printf(" poped:%d ",pop(Stack,&TOP));
	printf(" poped:%d ",pop(Stack,&TOP));
	printf(" poped:%d ",pop(Stack,&TOP));
	printf(" poped:%d ",pop(Stack,&TOP));

	return 0;
}