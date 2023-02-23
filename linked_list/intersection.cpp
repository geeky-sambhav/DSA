bool searchval(Node* head,int val){
    Node* curr=head;
    while(curr!=NULL){
        if(curr->data==val)
        {return false;}
    }
    return true;
}
// void insertAtTail(Node* &head,Node* &tail,int val){
//     Node* temp=new Node(val);
//     if(head==NULL){
//         head=temp;
//         tail=temp;
//     }
//     else{
//         tail->next=temp;
//         tail=temp;
        
//     }
// }
void insertAtTail(Node* &head,Node* &tail, int val){
    Node* temp=new Node(val);
    if (head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
    
}
Node* findIntersection(Node* head1, Node* head2)
{
    if (head1==NULL || head2==NULL){
    return NULL;
}
unordered_map<int,int> visited;
Node* curr1=head1;
Node* curr2=head2;
Node* anshead=NULL;
Node* anstail=NULL;

while(curr1!=NULL){
    
        visited[curr1->data]++;
        curr1=curr1->next;
   
}
    while(curr2!=NULL){
        if(visited[curr2->data]>0 ){
            Node* nodeToBeInserted=new Node(curr2->data);
           insertAtTail(anshead,anstail,curr2->data);
            visited[curr2->data]--;
        }
            curr2=curr2->next;
    }
    return anshead;
}