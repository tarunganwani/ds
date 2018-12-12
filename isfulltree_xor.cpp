
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node with the
   given key and NULL left and right pointer. */
struct Node *newNode(int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

bool isFullTree(Node *root){
	if(root == NULL)
		return true;
	if(root->left != NULL ^ root->right != NULL)
		return false;
	return isFullTree(root->left) &&isFullTree(root->right);
}

// Driver Program 
int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->right = newNode(40); 
    root->left->left = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    root->left->left->left = newNode(80); 
    root->left->left->right = newNode(90); 
    root->left->right->left = newNode(80); 
    root->left->right->right = newNode(90); 
    root->right->left->left = newNode(80); 
    root->right->left->right = newNode(90); 
    root->right->right->left = newNode(80); 
    root->right->right->right = newNode(90); 
  
    if (isFullTree(root)) 
        printf("The Binary Tree is full\n"); 
    else
        printf("The Binary Tree is not full\n"); 
  
    return(0); 
} 
