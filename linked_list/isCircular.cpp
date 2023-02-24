bool isCircular(Node *head)
{
    Node* temp= head->next;
    while(temp!=NULL){
        if(temp==head){
            return true;
        }else{
            temp=temp->next;
        }
        
    }
    return false;
   // Your code here
}