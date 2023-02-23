void jump (Node* &head,int k){
    if(head==NULL){
        return;
    }
    int count=0;
    while(count!=k){
        head=head->next;
        count++;
    }
}
int countNodes(Node* head){
    if(head==NULL){
        return NULL;
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
int intersectPoint(Node* head1, Node* head2)
{
    if (head1==NULL || head2==NULL){
        return -1;
    }
    Node* curr1=head1;
    Node* curr2=head2;
 int count1=countNodes(head1);
 int count2=countNodes(head2);
 int diff=abs(count1-count2);
 while ( curr1!=NULL && curr2!=NULL){
     if(curr1->next==curr2->next && curr1->next!=NULL && curr2->next!=NULL){
        return curr1->next->data;
    }
 if(count1>count2){
     jump(curr1,diff);
      count1=count1-diff;
 }
 else if(count2>count1){
     jump(curr2,diff);
     count2=count2-diff;
 }
 else{
     curr1=curr1->next;
     curr2=curr2->next;
 }
}
return -1;
    
}