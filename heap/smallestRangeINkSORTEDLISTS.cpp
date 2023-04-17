#include<queue>
#include<limits.h>

class node{
    public:
int data;
int row;
int col;
    node(int d,int r,int c){
       data=d;
       row=r;
       col=c;
    }
};

class compare {
public:
  bool operator()(node *a, node *b){
      return a->data>b->data;
  }
};

int kSorted(vector<vector<int>> &a, int k, int n) {

    priority_queue<node*,vector<node*>,compare>pq;
   int mini=INT_MAX;
   int maxi=INT_MIN;
    for(int i=0;i<k;i++){
        mini=min(mini,a[i][0]);
        maxi=max(maxi,a[i][0]);
        pq.push(new node(a[i][0],i,0));
    }

    int end=maxi;
    int start=mini;
    while(!pq.empty()){
        node* temp=pq.top();
        pq.pop();
        mini=temp->data;
            

    if(maxi-mini<end-start){
        end=maxi;
        start=mini;
    }
    if(temp->col+1<n){
        maxi=max(maxi,a[temp->row][temp->col+1]);
        pq.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));

    } else {
      break;
    }
    }
    return end-start+1;
}