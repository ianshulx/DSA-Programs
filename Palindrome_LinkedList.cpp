#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

class list
{
    node*head;
    node*tail;
    public:
    list()
    {
        head=NULL;
        tail=NULL;
    }

    //push
    void push(int data)
    {
        node*n= new node(data);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
        else
        {
            tail->next=n;
            tail=n;
        }
    }


    bool check()
    {
        node*slow=head;
        node*fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        node*tmp;
        node*prev=slow;
        slow=slow->next;
        prev->next=NULL;
        while(slow!=NULL)
        {
            tmp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=tmp;
        }
        slow=prev;
        fast=head;
        while(slow!=NULL)
        {
            if(slow->data!=fast->data) return false;
            else
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
       return true;
    }

    void print()
    {
        node*tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
    }
};

int main()
{
    list l;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        l.push(data);
    }
    if(l.check()) cout<<"true";
    else cout<<"false";
    //l.print();
    return 0;
}
