 //Muhammad Bilal


#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
}; Node *head1, *tail1, *head2, *tail2;

void insert(int data1, int data2){
	
	Node *temp1 = new Node;
	Node *temp2 = new Node;
	temp1->data = data1;
	temp1->next = NULL;
	
	temp2->data = data2;
	temp2->next = NULL;
	
	if (tail1 == NULL && tail2 == NULL){
		head1 = temp1;
		tail1 = temp1;
		
		head2 = temp2;
		tail2 = temp2;
	}
		tail1->next = temp1;
		tail1 = temp1;
	
		tail2->next = temp2;
		tail2 = temp2;
}

void similarity(){
	float sim = 0.0;
	float len = 0.0;
	Node *cur1 = new Node;
	cur1 = head1;
	Node *cur2 = new Node;
	cur2 = head2;
	while (cur1 != NULL && cur2 != NULL){
		if (cur1->data == cur2->data){
			sim++;
		}
		len++;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	float similar = (sim/len)*100;
	cout<<"Similarity : "<<similar<<endl;
}

void show(){
	Node *cur1 = new Node;
	cur1 = head1;
	Node *cur2 = new Node;
	cur2 = head2;
	while (cur1!=NULL && cur2!=NULL){
		cout<<"        "<<cur1->data<<"        ";
		cur1 = cur1->next;
		
		cout<<cur2->data<<"\n        ";
		cur2 = cur2->next;
	}	
}

int main(){
	head1 = NULL;
	head2 = NULL;
	tail1 = NULL;
	tail2 = NULL;
	
	insert(5,5);
	insert(7,3);
	insert(2,1);
	insert(6,6);
	insert(9,4);
	
	cout<<"\nShowing our Lists : \n";
	show();
	similarity();
}

