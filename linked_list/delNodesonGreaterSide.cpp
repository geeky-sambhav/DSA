class Solution
{
    public:
    Node *compute(Node *head)
    {
        if (head==NULL || head->next==NULL){
            return head;
        }
        head->next=compute(head->next);
        if(head->data<head->next->data){
            return head->next;
        }
        else{
            return head;
        }
    }
    
};
   