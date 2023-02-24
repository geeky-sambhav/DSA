
int countTriplets(struct Node* head, int x) 
{ 
    
    //1 sare elements vector mein daalo
    //2 pointer loop chalao
    
  vector<int>v;
  Node* curr=head;
  while(curr!=NULL){
      v.push_back(curr->data);
      curr=curr->next;
        }
    int c=0;
    for(int i=0;i<v.size();i++){
        int j=i+1;
        int k=v.size()-1;
        while(j<k){
            if(v[i]+v[j]+v[k]==x){
                c++;
                j++;
            }
            else if(v[i]+v[j]+v[k]>x){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return c;
    // code here.
} 