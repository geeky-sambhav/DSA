class disjointset{
vector<int>size,parent;
public:
disjointset(int n){
size.resize(n+1);
parent.resize(n+1);
for (int i=0;i<=n;i++){
size[i]=1;
parent[i]=i;
}

}


};