class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int,bool>visited;
        Node* curr=head;
         while(curr->next!=NULL){
             visited[curr->data]=true;
             if(visited[curr->next->data]==true){
                 Node* next_next=curr->next->next;
                 Node* del=curr->next;
                 delete(del);
                 curr->next=next_next;
             }
             else{
                 curr=curr->next;
             }
         }
         return head;
     // your code goes here
    }
};