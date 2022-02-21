// Binary Tree Implementation and Tree Traversal

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* left_child;
struct node* right_child;
};

struct node* create_node(int value)
{
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->left_child = temp->right_child = NULL;
	return temp;
}

// Inorder Traversal
void inorder_traversal(struct node* root) 
{
  if (root == NULL) 
  return;
  inorder_traversal(root->left_child);
  printf("%d ->", root->data);
  inorder_traversal(root->right_child);
  return;
}

// Preorder Traversal
void preorder_traversal(struct node* root) 
{
  if (root == NULL) 
  return;
  printf("%d ->", root->data);
  preorder_traversal(root->left_child);
  preorder_traversal(root->right_child);
  return;
}

// Postorder Traversal
void postorder_traversal(struct node* root) 
{
  if (root == NULL) 
  return;
  postorder_traversal(root->left_child);
  postorder_traversal(root->right_child);
  printf("%d ->", root->data);
  return;
}

int main()
{
	struct node* root = NULL;
	
	root = create_node(7);
	root->left_child = create_node(5);
	root->right_child = create_node(1);
	root->left_child->left_child = create_node(2);
	root->left_child->right_child = create_node(3);
	root->left_child->right_child->left_child = create_node(6);
	root->left_child->right_child->right_child = create_node(9);
	root->right_child->right_child = create_node(11);
	root->right_child->right_child->left_child = create_node(4);
	
	
	printf("Inorder Traversal \n");
  	inorder_traversal(root);

  	printf("\nPreorder Traversal \n");
  	preorder_traversal(root);

  	printf("\nPostorder Traversal \n");
  	postorder_traversal(root);
  	
	return 0;
}