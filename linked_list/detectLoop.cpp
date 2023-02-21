bool detectLoop(Node* head)
    {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
        }
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && slow!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        if(slow==fast){
            return true;
        }
        
       
        }
        return false;
    }