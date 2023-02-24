class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* findMid(Node* head){
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
    Node* solve(Node* &first,Node* &second){
        if(first->next==NULL){
            first->next=second;
            return first;
        }
        Node* curr1=first;
        Node* next1=curr1->next;
        Node* curr2=second;
        Node* next2=curr2->next;
        while(next1!=NULL && curr2!=NULL){
        if(curr1->data<=curr2->data && curr2->data<=next1->data){
          curr1->next=curr2;
          next2=curr2->next;
          curr2->next=next1;
          curr1=curr2;
          curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
        }
        return first;
    }
    Node* merge(Node* sort1,Node* sort2){
        if(sort1==NULL){
            return sort2;
        }
        if(sort2==NULL){
            return sort1;
        }
        if(sort1->data<=sort2->data){
           return solve(sort1,sort2);
              
        }
        else{
              return solve(sort2,sort1);
        
        }
    }
    Node* mergeSort(Node* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        Node* left=head;
        Node* middle=findMid(head);
        Node* right=middle->next;
        middle->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        Node* ans=merge(left,right);
        return ans;
        
        // your code here
    }
};