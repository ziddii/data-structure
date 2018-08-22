#include<stdio.h>

struct BtNode
{
	int data;
	struct BtNode* leftRoot;
	struct BtNode* rightRoot;
};

int numberOfLeaf(struct BtNode* root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->leftRoot==NULL&&root->rightRoot==NULL)
			return 1;

		int xl= numberOfLeaf(root->leftRoot);
		int xr= numberOfLeaf(root->rightRoot);

		return xl + xr;
	}
}


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


	printf("%d",numberOfLeaf(root));
	return 0;
}