int getcount(Node* head){
 if(head==NULL){
     return 0;
      }
      int i=0;
      while(head!=NULL){
          i++;
          head=head->next;
      }
      return i;
}
int getNthFromLast(Node *head, int n)
{
int count=getcount(head);
if(n>count){
    return -1;
}
Node* temp=head;
int i=0;
while( i<(count-n)){
    temp=temp->next;
    i++;
}
return temp->data;
}