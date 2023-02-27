long long int mod=pow(10,9)+7;
void convertToInt(Node* head,long long &i){
    Node* temp=head;
    while(temp!=NULL){
        i=(i*10+temp->data)%mod;
        temp=temp->next;
    }
 
}
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    
   
  
    long long  int1=0;
    long long int2=0;
 convertToInt(l1,int1);
 convertToInt(l2,int2);
  return (int1*int2)%mod;
}