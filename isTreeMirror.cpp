#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
};
  
/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data  = data; 
    node->left  =  node->right  = NULL; 
    return(node); 
} 

bool areMirror(Node *root1, Node *root2){
	
	//base condition
	if(root1 == NULL && root2 == NULL)
		return true;

	if(root1 != NULL && root2 == NULL)
		return false;
	
	if(root1 == NULL && root2 != NULL)
		return false;

	return (root1->data == root2->data) && areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);
}


/* Driver program to test areMirror() */
int main() 
{ 
    Node *a = newNode(1); 
    Node *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 
  
    areMirror(a, b)? cout << "Yes" : cout << "No"; 
  
    return 0; 
} 
