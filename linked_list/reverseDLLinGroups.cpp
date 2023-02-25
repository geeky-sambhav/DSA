Node *reverseDLLInGroups(Node *head, int k) {
    if(head==NULL ){
		return head;
	}
	int i=0;
	Node* temp=head;
	Node* prev=NULL;
Node* next=NULL;
while(i<k && temp != NULL){
	next=temp->next;
	temp->next=prev;
	temp->prev=next;  
		if(prev) {
			prev->prev=temp;
		}
	prev=temp;
	temp=next;
		i++;
}
if (temp) {
  Node *reversed = reverseDLLInGroups(temp, k);
head->next=reversed;

}
return prev;
}

