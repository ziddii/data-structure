#include<stdio.h>

struct BtNode
{
	int data;
	struct BtNode* leftRoot;
	struct BtNode* rightRoot;
};

void printTree(struct BtNode* root,int number)
{
	if(root==NULL)
		return ;
	else
	{
		printTree(root->leftRoot,number+1);
		printf("%*c%d\n",number*4,' ',root->data);
		printTree(root->rightRoot,number+1);

	}
}

int main()
{
	struct BtNode root[]={
							{4,root+1,root+4},
							{7,root+2,root+3},
							{8,NULL,NULL},
							{10,NULL,NULL},
							{5,root+5,root+6},
							{20,NULL,NULL},
							{15,NULL,NULL}	};


	printTree(root,0);

	return 0;
}