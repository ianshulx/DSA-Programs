// A C++ program for in-place conversion of Binary Tree to DLL
#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

void BinaryTree2DoubleLinkedList(node* root, node** head)
{
	if (root == NULL)
		return;
	static node* prev = NULL;
	BinaryTree2DoubleLinkedList(root->left, head);
	if (prev == NULL)
		*head = root;
	else {
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	BinaryTree2DoubleLinkedList(root->right, head);
}

node* newNode(int data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

void printList(node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->right;
	}
}

int main()
{
	node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	// Convert to DLL
	node* head = NULL;
	BinaryTree2DoubleLinkedList(root, &head);

	// Print the converted list
	printList(head);

	return 0;
}
