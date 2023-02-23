class Solution
{
    public:
    void insertAtTail(Node* &head,Node* &tail,int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    struct Node* reverse(struct Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    struct Node* add(struct Node* first, struct Node* second){
        Node* anshead=NULL;
        Node* anstail=NULL;
        int carry=0;
        while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        int val2=0;
            if(first){ 
                val1=first->data;
        }
      
        if(second){
            val2=second->data;
        }
        
        int sum=val1+val2+carry;
        carry=sum/10;
        int digit=sum%10;
        insertAtTail(anshead,anstail,digit);
        if(first){
            first=first->next;
            
        }
        if(second){
            second=second->next;
        }
    }
    return anshead;}
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        Node* ans=add(first,second);
        ans=reverse(ans);
        return ans;
        // code here
    }
};