#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node* prev;

Node (int data){
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
}
};
void insertAtHead(Node* &tail,Node*  &head,int data){

    if(head==NULL){
        Node*temp=new Node(data);
        head=temp;
        tail=temp;
    }
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node* &tail,Node* &head,int data){
     if(tail==NULL){
        Node*temp=new Node(data);
        head=temp;
        tail=temp;
    }
Node* temp=new Node(data);
tail->next=temp;
temp->prev=tail;
tail=temp;

}
void insertAtMiddle(Node* &tail,Node* &head,int data,int pos){
if (pos==1){
    insertAtHead(tail,head,data);
    return;
}
else{
    Node*temp=head;
for (int i = 1; i < pos-1; i++)
{
temp=temp->next;
    /* code */
}
if (temp->next==NULL)
{
    insertAtTail(tail,head,data);
    /* code */
}
else
{
    Node* nodeToBeInserted= new Node(data);
    nodeToBeInserted->next=temp->next;
    temp->next->prev=nodeToBeInserted;
    temp->next=nodeToBeInserted;
    nodeToBeInserted->prev=temp;
}


}
}
void print(Node *&head){
    Node *temp=head;
    while (temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
Node* node1=new Node(10);
Node* head=node1;
Node* tail=node1;
print(head);
insertAtHead(head,20);
insertAtHead(head,30);
insertAtHead(head,40);
print(head);
insertAtTail(tail,head,20);
insertAtTail(tail,head,30);
insertAtTail(tail,head,40);
print(head);
insertAtMiddle(tail,head,25,3);

return 0;}