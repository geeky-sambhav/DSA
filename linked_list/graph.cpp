#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
public:
unordered_map<int,list<int>> adj;
void createEdge(int u,int v,bool direction){
    //direction 0 = undirected
    //direction 1 = directed
     adj[u].push_back(v);
     if (direction==0)
     {
        adj[v].push_back(u);
        /* code */
     }}
void printGraph(){
    for(auto i:adj){
        cout<<i.first<<"-->"<<" ";
        for(auto j:i.second){
            cout<<j<<" ,";
        }
        cout<<endl;
    }
}

};
int main(){
int n=5;
int m=6;
    int u,v;
    cout<<"enter u and v"<<endl;
graph op;
for (int i = 0; i < m; i++)
{
    cin>>u>>v;
    op.createEdge(u,v,0);

}
op.printGraph();
return 0;}