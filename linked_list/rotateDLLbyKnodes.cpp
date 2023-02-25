DLLNode* findTail(DLLNode* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	DLLNode* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	return temp;
}
DLLNode* rotateDLL(DLLNode* head, int k) 
{
	int i=0;
	DLLNode* temp=head;
	DLLNode* next=temp->next;
	DLLNode* tail=findTail(head);
	while(i<k){
		next=temp->next;
		next->prev=NULL;
		
		tail->next=temp;
		temp->prev=tail;
		temp->next=NULL;
		tail=temp;
		temp=next;
		head=temp;
		i++;


	}
    
return head;
}