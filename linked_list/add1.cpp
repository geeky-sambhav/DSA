
class Solution
{
    public:
    void insertAtTail( Node* &head,  Node* &tail,int val){
      Node* temp=new Node(val);
      if(head==NULL){
          head=temp;
          tail=temp;
          return;
      }
    else{
        tail->next=temp;
        tail=temp;
    }}
    Node* reverse(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
               
        }
        return prev;
    }
    Node* add(Node* head){
        Node* anshead=NULL;
        Node* anstail=NULL;
        if(head==NULL){
            return NULL;
        }
        int carry=1;
        Node* curr=head;
        while(curr!=NULL || carry!=0){
           int sum = (curr ? curr->data : 0) + carry;
            int digit=sum%10;
            carry=sum/10;
         insertAtTail(anshead,anstail,digit);
            if (curr) {
            curr = curr->next;
        }
        }
        return anshead;
    }
    Node* addOne(Node *head) 
    {
        if(head==NULL){
            return NULL;
        }
  head=reverse(head);
   Node* ans=add(head);
   ans=reverse(ans);
   return ans;
    }
};