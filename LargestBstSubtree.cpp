#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data=0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

 class Pair {
    public:
    Node *node=nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
  };

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}


void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}



int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; 
}
class pentapair
{
  public:
  int size=0;
  Node* root=NULL;
  int max=INT_MIN;
  int min=INT_MAX;
  bool isbst=true;
};

pentapair* labst(Node* node){
  if(node==NULL){
    return new pentapair();
  }

  pentapair* l =labst(node->left);
  pentapair* r= labst(node->right);

  pentapair* ans= new pentapair();
   bool atnode=(l->max<node->data) && (r->min>node->data);
    
    ans->isbst=((l->isbst==true) && (r->isbst==true)  && (atnode==true)) ? true:false;
    ans->min=min(l->min,min(r->min,node->data));
    ans->max=max(l->max,max(r->max,node->data));

    if(ans->isbst==true){
      ans->size=l->size+r->size+1;
      ans->root=node;

    }
    else{
      ans->size=max(l->size,r->size);
      ans->root=l->size>r->size ? l->root : r->root;
    }
    return ans;  
  

}

 
int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp;
      if (tmp=="n") {
        arr[i] = -1;
      } else {
        arr[i] = stoi(tmp);
      }
    }
    
    Node *root = constructTree(arr);

    pentapair* r = labst(root);
    cout<<r->root->data<<"@"<<r->size;
    
    
    
}
