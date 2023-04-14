class Solution{
public:
void heapify(vector <int> &v,int n,int i){
int largest=i;
int left=2*i+1;
int right=2*i+2;
if(left<n && v[largest]<v[left]){
            largest=left;
      }
      if(right<n && v[largest]<v[right]){
          largest=right;
      }
if(largest!=i){
swap(v[largest],v[i]);
heapify(v,n,largest);
}
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
vector<int>v;
for(auto i:a)v.push_back(i);
for(auto i:b)v.push_back(i);
int size=v.size();
    for(int i=(size/2)-1;i>=0;i--){
        heapify(v,size,i);
    }

    return v;
}



};