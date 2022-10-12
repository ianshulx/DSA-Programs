largest bst subtree

//code

#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
   int val;
   TreeNode *left, *right;
   TreeNode(int data){
      val = data;
      left = NULL;
      right = NULL;
   }
};
void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         if(val != NULL)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      }
      else{
         q.push(temp->left);
      }
      if(!temp->right){
         if(val != NULL)
            temp->right = new TreeNode(val);
         else
            temp->right = new TreeNode(0);
         return;
      }
      else{
         q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int< v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}
struct Data{
   int sz;
   int maxVal;
   int minVal;
   bool ok;
   Data(){}
   Data(int a, int b, int c, bool d){
      sz = a;
      minVal = b;
      maxVal = c;
      ok = d;
   }
};
class Solution {
public:
   int ret;
   Data solve(TreeNode* node){
      if (!node)
         return Data(0, INT_MAX, INT_MIN, true);
      Data left = solve(node->left);
      Data right = solve(node->right);
      Data curr;
      curr.ok = false;
      if (node->val >= right.minVal) {
         return curr;
      }
      if (node->val <= left.maxVal) {
         return curr;
      }
      if (left.ok && right.ok) {
         curr.sz = 1 + left.sz + right.sz;
         curr.ok = true;
         curr.maxVal = max(node->val, right.maxVal);
         curr.minVal = min(node->val, left.minVal);
      }
      if (curr.ok)
         ret = max(ret, curr.sz);
      return curr;
   }
   int largestBSTSubtree(TreeNode* root){
      ret = 0;
      solve(root);
      return ret;
   }
};
main(){
   Solution ob;
   vector<int< v = {10,5,15,1,8,NULL,7};
   TreeNode *root= make_tree(v);
   cout << (ob.largestBSTSubtree(root));
}
