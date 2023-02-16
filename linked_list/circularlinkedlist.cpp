// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;

class Node{
public:
Node* next;
int data;
Node(int data){
    this->data=data;
    this->next=NULL;
}};

void insert(Node* &tail,int element,int data){
if (tail==NULL)
{
    Node* newNode=new Node(data);
    tail=newNode;
    newNode->next=newNode;
    /* code */
}
else{
    Node* curr=tail;
while (curr->data!=element)
{
    curr=curr->next;
    /* code */
}
Node*temp=new Node(data);
temp->next=curr->next;
curr->next=temp;

}


}
void print(Node* tail){
    Node *temp=tail;
      if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

do
{
    cout<<tail->data<<endl;
    tail=tail->next;
} while (tail!=temp);


}

void deleteNode(Node* &tail,int element){
if (tail==NULL)
{
    cout<<"No element found"<<endl;
    /* code */
    return;
}
else{
Node* prev=tail;
Node* curr=prev->next;
    while (curr->data!=element)
    {
        prev=curr;
        curr=curr->next;
    }
//1 node
if (prev==curr)
{
    /* code */

    tail=NULL;
    return;
}


prev->next=curr->next;
if (tail==curr)
{
    tail=prev;
}

curr->next=NULL;
delete curr;
}



}
int main(){
Node* tail=NULL;
insert(tail,5,6);
cout<<"tail is"<<tail->data<<endl;
// print(tail);
insert(tail,6,16);
cout<<"tail is"<<tail->data<<endl;
// print(tail);
insert(tail,16,26);
cout<<"tail is"<<tail->data<<endl;
// print(tail);
insert(tail,26,36);
cout<<"tail is"<<tail->data<<endl;
// print(tail);
insert(tail,36,46);
cout<<"tail is"<<tail->data<<endl;
// print(tail);
insert(tail,46,56);
cout<<"tail is"<<tail->data<<endl;
// print(tail);
insert(tail,46,66);
cout<<"tail is"<<tail->data<<endl;
// deleteNode(tail,6);
// deleteNode(tail,16);
// deleteNode(tail,26);
// deleteNode(tail,36);
// deleteNode(tail,46);

print(tail);
return 0;                                                                                                                   

 ;}
 