#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A linked list Node
struct Node
{
	int data;
	struct Node* next;
};

// Function to delete the last occurrence
void deleteLast(struct Node** head, int x)
{
	struct Node** tmp1 = NULL;
	while (*head)
	{
			if ((*head)->data == x)
			{
				tmp1 = head;
			}
			head = &(*head)->next;
	}
	if (tmp1)
	{
		struct Node* tmp = *tmp1;
		*tmp1 = tmp->next;
		free(tmp);
	}
}

// Utility function to create a new node with
// given key
struct Node* newNode(int x)
{
	Node* node = new Node ;
	node->data = x;
	node->next = NULL;
	return node;
}

// This function prints contents of linked
// list starting from the given Node
void display(struct Node* head)
{
	struct Node* temp = head;
	if (head == NULL)
	{
		cout << "NULL\n";
		return;
	}
	while (temp != NULL)
	{
		cout << temp->data <<" --> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

// Driver code
int main()
{
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(4);
	head->next->next->next->next->next->next = newNode(4);
	
	cout << "Created Linked list: ";
	display(head);
	
	// Pass the address of the head pointer
	deleteLast(&head, 4);
	cout << "List after deletion of 4: ";
	
	display(head);
	
	return 0;
}
