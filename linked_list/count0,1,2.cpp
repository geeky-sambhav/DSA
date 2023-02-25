class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int count0=0;
        int count1=0;
        int count2=0;
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data==0){
                count0++;
            }
            else if(curr->data==1){
                count1++;
            }
            else{
                count2++;
            }
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
        if(count0!=0){
            curr->data=0;
            curr=curr->next;
            count0--;
        }
        else if(count1!=0){
            curr->data=1;
            curr=curr->next;
            count1--;
        }
        else{
            curr->data=2;
            curr=curr->next;
            count2--;
        }
    }
    return head;}
};