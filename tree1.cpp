#include<iostream>
#include<queue>
#include<vector>
#include <bits/stdc++.h>

using namespace std;
template<class T>
class treenode{
    public:
    T data;
    vector<treenode<T>*>children;
    treenode(int data1){
        data=data1;
    }

    // delete tree without fuction as have to delete own as we created dynamic
    ~treenode(){
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
        
    }


};

// taking input horizontally 

treenode<int>* takeinput(){
    int tdata,n;
    cout<<"enter root data"<<endl;
    cin>>tdata;
    treenode<int>*root=new treenode<int>(tdata);
    cout<<"enter the number of children of root"<<endl;
    cin>>n;
       for (int i = 0; i < n; i++)
    {
        treenode <int>* child=takeinput();
        root->children.push_back(child);

        


    }
    return root;
    
}


// taking input levelwise or vertically better one less confusion

treenode<int> * takeinputv(){
    int rdata;
    cout<<"enter root node of tree"<<endl;
    cin>>rdata;
    treenode<int>*root=new treenode<int>(rdata);

    queue<treenode<int>*> pendingnodes;

    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        treenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        int n;
        cout<<"enter no of child of"<<front->data<<endl;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int childd;
            cout<<"enter"<<i<<"child of"<<front->data<<endl;
            cin>>childd;
            treenode<int>*child=new treenode<int>(childd);
            front->children.push_back(child);
            pendingnodes.push(child);
            
        }
        
    }
        return root;


}



//  printing data horizontally 
void printt(treenode<int>* root){

    if (root==NULL){
        return;
    }


    // above line is not base case it is a h-case 
    // no base case but below line behaves as this
    cout<<root->data<<":";

//  for printing children and root diffrently 
     for (int i = 0; i<root->children.size(); i++)
     {
        cout<<root->children[i]->data<<",";
     }
     cout<<endl;
     

    for (int i = 0; i < root->children.size(); i++)
    {
        printt(root->children[i]);
    }
    

}



// printing data levelwize vertically (better one)
void printv(treenode<int>*root){
    int m=1;
    int sum=root->data;
    queue<treenode<int>*> pendingnodes;
      pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        treenode<int>*front=pendingnodes.front();
        cout<<front->data<<": ";
        pendingnodes.pop();
        int i=0;
        for (int i = 0; i<front->children.size(); i++)
     {
        cout<<front->children[i]->data<<",";
        pendingnodes.push(front->children[i]);
        sum=sum+front->children[i]->data;
        m++;

     }
     cout<<endl;
     


}
cout<<"no of nodes "<<m<<endl;
cout<<"sum of nodes "<<sum<<endl;

}

// also counting no of nodes recursively 
int numnodes(treenode<int>* root){
    int ans=1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans=ans+numnodes(root->children[i]);
    }
    return ans;
    
}

// sum of nodes recursively
int sumnodes(treenode<int>* root){
    int sum=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum=sum+sumnodes(root->children[i]);
    }
    return sum;
    
}
// largest of nodes recursively
int largestnodes(treenode<int>* root){
    int large=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {

        if(large<root->children[i]->data){

        large=largestnodes(root->children[i]);
        }
    }
    return large;
    
}



// int heightnodes(treenode<int>*root){
//     int height=root->children.size();
//     if 
// }


int height(treenode<int>* root)
{
    if (!root)
        return 0;
    //leaf node
    if (root->children.size() == 0) {
        return 1;
    }

    int max_child_height = INT_MIN;
    //height=1+max(subtree heights)
    //subtree heights found recursively
    for (int i = 0; i < root->children.size(); i++) {
        max_child_height = max(max_child_height, height(root->children[i]));
    }
    return 1 + max_child_height;
}


void printatlevelk(treenode<int>*root,int k){
    if (k==0){
        cout<<root->data<<endl;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printatlevelk(root->children[i],k-1);
    }
    
}






// count leaf nodes 
int leafnodes(treenode<int>* root){
    int ans=0;
    if (root->children.size() == 0) {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans=ans+leafnodes(root->children[i]);
    }
    return ans;
    
}





void preorder(treenode<int>*root){
    cout<<root->data<<endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
    
}



// queue daalna padega for proper postorder
void postorder(treenode<int>*root){
    if (root->children.size() == 0) {
        cout<<root->data<<endl;
    }
    for (int i = 0; i <root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    
}



void deletetree(treenode<int>*root){
    for (int i = 0; i < root->children.size(); i++)
    {
        deletetree(root->children[i]);
    }
    delete root;
    
}



int main(){

    // treenode<int>*root=new treenode<int>(1);
    // treenode<int>*node1=new treenode<int>(2);
    // treenode<int>*node2=new treenode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    
    treenode <int>* root=takeinputv();
    printv(root);
    int i=sumnodes(root);
    cout<<i<<endl;
    int l=largestnodes(root);
    cout<<l<<endl;
    int k=height(root);
    cout<<k<<endl;
    int n=leafnodes(root);
    cout<<n;
    postorder(root);
return 0;

}