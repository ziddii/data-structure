#include<stdio.h>

struct BtNode
{
	int data;
	struct BtNode* leftRoot;
	struct BtNode* rightRoot;
};

int numberOfRoots(struct BtNode* root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->leftRoot==NULL&&root->rightRoot==NULL)
			return 0;

		int xl= numberOfRoots(root->leftRoot);
		int xr= numberOfRoots(root->rightRoot);

		return xl + xr + 1;
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


	printf("%d",numberOfRoots(root));
	return 0;
}