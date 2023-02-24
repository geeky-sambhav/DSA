class Solution{
  public:
  Node* reverse(Node* &head){
      Node* prev=NULL;
        Node* next=NULL;
        Node* curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
      
  }
  Node* findMiddle(Node* head){
      if(head==NULL || head->next==NULL){
            return head;
        }
        Node* slow=head;
        Node* fast=slow->next;
        while(fast!=NULL && fast->next!=NULL){
            
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {if (head==NULL){
        return NULL;
    }
    Node* mid=findMiddle(head);
    Node* left =head;
    Node* right=reverse(mid->next);
    while(right){
        if(left->data==right->data){
        left=left->next;
        right=right->next;
    }
    else{
        return false;
    }
    }
    return true;}
};