#include<stdio.h>
#include<stdlib.h>

typedef struct BST_node_struct
{
	int index;
	struct BST_node_struct* left;
	struct BST_node_struct* right;
	
}BST_node;

BST_node* createNode(int index)
{
	BST_node* temp = (BST_node *)calloc(1, sizeof(BST_node));
	if(temp != NULL)
	{
		temp -> index = index;
		temp -> left = NULL;
		temp -> right = NULL;
		return temp;
	}
	return NULL;
}


BST_node* insertNode(BST_node* root, BST_node* insert)
{
	if (insert != NULL)
	{
		if (root == NULL)
		{
			return insert;
		}
		if (root != NULL)
		{
			if(insert -> index < root -> index)
			{
				root -> left = insertNode(root -> left, insert);
			}
			else if(insert -> index > root -> index)
			{
				root -> right = insertNode(root -> right, insert);
			}
			return root;
		}
	}
}
BST_node* searchNode(BST_node* root, int index)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(root != NULL)
	{
		if (root -> index == index)
		{
			return root;
		}
		else if (root -> index > index)
		{
			return searchNode(root -> left, index)
		}
		else
		{
			return searchNode(root -> right, index)
		}
	}
}


BST_node* findNextBiggest (BST_node* rootAtRight)
{
	BST_node* temp = rootAtRight;
	while(temp -> left != NULL)
	{
		temp = temp -> left;
	}
	return temp;
}

BST_node* deleteNode(BST_node* root, int index)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(root -> index == index)
	{
		if(root -> right == NULL && root -> left == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root -> left == NULL)
		{
			BST_node* temp = root -> right;
			free(root);
			return temp;
		}
		else if (root -> right == NULL)
		{
			BST_node* temp = root -> left;
			free(root);
			return temp;
		}
		else
		{
			BST_node* temp = findNextBiggest(root -> right);
			root -> index = temp -> index;
			root -> right = deleteNode(root -> right, temp -> index);
			return root;
		}
	}
	else if (root -> index > index)
	{
		root -> left = deleteNode(root -> left, index);
	}
	else 
	{
		root -> right = deleteNode(root -> right, index);
	}
	return root;
}

void printInOrderNode (BST_node* root)
{
	if (root != NULL)
	{
		printInOrderNode(root -> left);
		printf("%d\n");
		printInOrderNode(root -> right);
	}
}

void printPreOrderNode (BST_node* root)
{
	if (root != NULL)
	{
		printf("%d\n");
		printPreOrderNode(root -> left);
		printPreOrderNode(root -> right);
	}
}

void printPostOrderNode (BST_node* root)
{
	if (root != NULL)
	{
		printPostOrderNode(root -> left);
		printPostOrderNode(root -> right);
		printf("%d\n");
	}
}





int main()
{
	return 0;
}