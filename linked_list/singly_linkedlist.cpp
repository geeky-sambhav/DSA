#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node (int data){
    this->data=data;
    this->next=NULL;
}


};


void insertAtHead(Node* &head,int data){
    Node* temp= new Node(data);
temp->next=head;
head=temp;
}
void insertAtTail(Node* &tail,int data){
    Node* temp= new Node(data);
    tail->next=temp;
    tail=temp;
}
void insertAtMiddle(Node* &head,Node* &tail,int position,int data){

    if (position==1)
    {
        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    int count=1;
    for (int i = 1; i < count-1; i++)
    {
        temp=temp->next;

        
    }
if (temp->next==NULL)
{
    insertAtTail(tail,data);
}

    Node* nodeTobeinserted=new Node(data);
    nodeTobeinserted->next=temp->next;
    temp->next=nodeTobeinserted;
    
}


void print(Node* &head){
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data;
    temp=temp->next;
    cout<<endl;
}
}
void deleteNode(Node*&head,Node* &tail,int position){
    if (position==1)
    {Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
        /* code */
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        for (int i = 1; i < position; i++)
        {
            prev=curr;
            curr=curr->next;
            /* code */
        }
        
prev->next=curr->next;
curr->next=NULL;
delete curr;
if (prev->next==NULL)
{    tail=prev;
    /* code */
}
    }
 
}
int main(){
Node* node1=new Node(20);
Node* head=node1;
Node* tail=node1;
insertAtTail(tail,30);
insertAtTail(tail,40);
insertAtMiddle(head,tail,2,34);
insertAtMiddle(head,tail,1,10);
print(head);
cout<<"head is "<<head->data<<endl;
cout<<"tail is "<<tail->data<<endl;
deleteNode(head,tail,5);
cout<<endl;
print(head);
cout<<"head is "<<head->data<<endl;
cout<<"tail is "<<tail->data<<endl;

return 0;}