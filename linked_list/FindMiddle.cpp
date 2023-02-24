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