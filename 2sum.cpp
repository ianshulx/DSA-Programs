#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
   struct Node* left;
   struct Node* right;

    Node(int val){
       data = val;
       left = NULL;
       right = NULL;
    }
};

vector<int> tolist(Node* A, vector<int>& list){
    if(A==NULL){
        return list;
    }
    tolist(A->left, list);
    list.push_back(A->data);
    tolist(A->right, list);
    return list;
}

int tSum(Node* A, int B) {
    vector<int> a1;
        vector<int> a2 = tolist(A, a1);
 
        int start = 0; // Starting index of a2
 
        int end = (int)a2.size() - 1; // Ending index of a2
 
        while (start < end) {
 
            if (a2[start] + a2[end] == B) // Target Found!
            {
                
                return 1;
            }
 
            if (a2[start] + a2[end]  > B) // decrements end
            {
                end--;
            }
 
            if (a2[start] + a2[end]  < B) // increments start
            {
                start++;
            }
        }
        return 0;
}

int main(){
      Node* root = new Node(3);
     root->left = new Node(2);
     root->right = new Node(7);
     root->left->left = new Node(1);
     root->right->left = new Node(5);
     root->right->right = new Node(8);
     cout << tSum(root, 54);
     return 0;
}
