class ListNode{
  public:
      int val;
      ListNode* next;
      
      ListNode(int data){
        this->val=data;
        this->next=nullptr;
      }
};


//iterative method
ListNode* reverseIteraive(ListNode* head){
  if(!head || !head->next) return head;
  ListNode *curr=head,*prev=nullptr;
  while(curr){
    ListNode* n=curr->next;
    curr->next=prev;
    prev=curr;
    curr=n;
  }
  return prev;
}

//recursive method
ListNode* reverseRecursive(ListNode* head){
  if(!head || !head->next) return head;
  
  ListNode* revHead=reverseRecursive(head->next);
  head->next->next=head;
  head->next=nullptr;
  return revHead;
}
