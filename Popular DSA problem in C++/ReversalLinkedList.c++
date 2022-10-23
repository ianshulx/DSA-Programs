#include<bits/stdc++.h>
using namespace std;

/* creating node structure */
struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
struct LinkedList{
    Node* head;
    LinkedList(){head= NULL;}
    void reverse(){
        Node* current =head;
        Node*prev=NULL;
        Node*next=NULL;
        while(current!=NULL){
            //storing next
        next=current->next;
        //reverse the current node's pointer
        current->next=prev;
        //moving pointers one position ahead
        prev=current;
        current=next;
        }
        head=prev;
    }
    /*function to print the linked list*/
    void print(){
        struct Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }
    void push(int data){
        Node*temp=new Node(data);
        temp->next=head;
        head=temp;
    }

};

int main(){
    /*start with the empty list*/
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;

}
