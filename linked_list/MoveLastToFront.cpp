class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
            
        }
        curr->next=head;
        head=curr;
        prev->next=NULL;
        return head;
    }
};