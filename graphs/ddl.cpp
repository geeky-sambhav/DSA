class DisjointSet{
vector<int>rank,parent;
DisjointSet(){
rank.resize(n+1,0);
parent.resize(n+1);
for (int i = 0; i <= n; i++)
{
    parent[i]=i;
}

}
int findulp(int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=findulp(parent[u]);
}

void unionbyrank(int u,int v){
int ulpu=findulp(u);
int ulpv=findulp(v);
if(ulpu==ulpv){
return;
}
if(rank[ulpu]<rank[ulpv]){
    parent[ulpv]=ulpu
}

}




};