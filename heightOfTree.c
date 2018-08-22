#include<stdio.h>

struct BtNode
{
	int data;
	struct BtNode* right;
	struct BtNode* left;
};



int max(int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}

void printTree(struct BtNode* root, int n)
{
	if(root==NULL)
		return;

	printTree(root->right, n+1);
	printf("%*c%d\n", n*5, ' ', root->data);
	printTree(root->left, n+1);
}



int height(struct BtNode* root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->left==NULL&&root->right==NULL)
			return 0;

		return max(height(root->left), height(root->right)) + 1;
	}
}


int main()
{
	
struct BtNode root[]={
							{4,root+1,root+4},
							{7,root+2,root+3},
							{8,root+7,NULL},
							{10,NULL,NULL},
							{5,root+5,root+6},
							{20,NULL,NULL},
							{15,NULL,NULL},
							{105,NULL,NULL}	};

		printTree(root,0);
		printf("Height of Tree: %d", height(root));

	return 0;
}