// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }
//  void InsertAtHead(Node* &head,int data){
//     Node* temp=new Node(data);
//     this->next=head;            //iska next ka address head ko point krega
//     head=temp;                      //temp ko head krdo
//  }


// };
// int main(){
// Node* node1=new Node(10);

// return 0;}


#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

     Node(int data){
        this -> data= data;
        this -> next= NULL;
    }
    ~Node(){
        int value=this->data;
       
        cout<<"Node deleted with value"<<value<<endl;
    }
};
void insertAtHead(Node*  &head,int data){
        Node* temp=new Node(data);
       temp->next=head;
        head=temp;
            }
            
                   void print(Node*  &head){
        Node* temp=head;
    while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;}
            }

// Insert at tailx
void insertAtTail(Node*  &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
   tail=temp;
}

//Insert anywhere
void insertAnywhere(Node*  &head,Node*  &tail,int position,int data){
    int count=1;
    Node* temp=head;
    if (position==1)    
    {
        insertAtHead(head, data);
        return;
    }
    
    while (count<position-1)
    {
        temp=temp->next;
    count++;
}
//insert at last
    if (temp->next==NULL)
    {
       insertAtTail(tail,data);
       return;
        /* code */
    }
    
    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;  

}

//deleting
void deleteNode(Node* &head,Node* &tail,int position){
    if (position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;

        //  LAST ELEMENT DELETE
        if (curr->next==NULL)
        {
     tail=prev;
            /* code */
        }
        
        curr->next=NULL;
        delete curr;
    }
}

int main(){
Node* node1=new Node(10);
// cout<<node1->data<<endl;
Node* head=node1;
Node* tail=node1;
insertAtTail(tail,20);
insertAtTail(tail,30);
insertAnywhere(head,tail,3,50);
print(head);
// cout<<head->data<<endl;
// cout<<tail->data<<endl;
cout<<"hello"<<endl;
deleteNode(head,tail,);
print(head);
cout<<"opldhcn"<<endl;
cout<<tail->data<<endl;
return 0;}