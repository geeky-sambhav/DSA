class Solution
{
    public:
    Node* startOfLoop(Node* head){
        if(head==NULL){
            return NULL;
        }
        Node* intersect=intersection(head);
        Node* slow=head;
        if(intersect==NULL){
            return NULL;
        }
        while(intersect!=slow){
                intersect=intersect->next;
                slow=slow->next;
            }
            return slow;
        
    }
    Node* intersection(Node* head){
         if(head==NULL){
            return NULL;
        }
         Node* fast=head;
      Node* slow=head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            return slow;
          }
          }
       return NULL; 
    }
    
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head==NULL ){
            return ;
        }
        Node* start=startOfLoop(head);
          if(start==NULL){
        return ;
    }
        Node* temp=start;
        while(temp->next!=start){
        temp=temp->next;
        }
        temp->next=NULL;
         }
}; 