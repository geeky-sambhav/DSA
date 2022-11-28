Node* node1=new Node(10);
// cout<<node1->data<<endl;
Node* head=node1;
Node* tail=node1;
insertAtTail(tail,20);
insertAtTail(tail,30);
insertAnywhere(head,tail,5,50);
print(head);