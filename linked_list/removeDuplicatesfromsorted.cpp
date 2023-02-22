Node *removeDuplicates(Node *head)
{
     if (head==NULL){
        return NULL;
    }
    Node* curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* next_next=curr->next->next;
            Node* del=curr->next;
            delete(del);
            curr->next=next_next;
        } else {
          curr = curr->next;
        }
    }
    return head;
}