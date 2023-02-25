class Solution
{
    public:
    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
          
        }
        else{
        tail->next=newnode;
        tail=newnode;}
    }
    Node *copyList(Node *head)
    {
        
        //step 1 creating a clone
        Node* temp=head;
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        while(temp!=NULL){
            insertAtTail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        //step 2 adding clonenodes bewteen original nodes
        temp=head;
        Node* cloneNode=clonehead;
       while(temp!=NULL){
           Node* next=temp->next;
           temp->next=cloneNode;
           temp=next;
           next=cloneNode->next;
           cloneNode->next=temp;
           cloneNode=next;
       }
        // step 3 copying random pointers
        temp=head;
        
        while(temp!=NULL){
            if(temp->next!=NULL){
                        temp->next->arb=temp->arb?temp->arb->next:temp->arb;
            
        }
        temp=temp->next->next;
        
    }
    //step4 converting to original linked list
    temp=head;
    cloneNode=clonehead;
    while(temp!=NULL && cloneNode!=NULL){
     temp->next=temp->next->next;
     cloneNode->next=temp->next;
        temp->next=cloneNode->next;
        temp=temp->next;
        if(temp!=NULL){
            cloneNode->next=temp->next;
        }
        cloneNode=cloneNode->next;
    }
 
    
return clonehead;}
};