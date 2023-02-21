// USING LOOPS

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

//USING RECURSION
if(head==NULL || head->next==NULL){
            return head;
        }
        Node* reversed=reverseList(head->next);
       
        head->next->next=head;
        head->next=NULL;
        return reversed;
        
        
        
    