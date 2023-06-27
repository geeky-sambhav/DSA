class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for (auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    for (int i=0;i<n;i++){
        for (auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for (int i=0;i<n;i++){
        if(indegree[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
         ans.clear();
         int size=q.size();
         for (int i=0;i<size;i++){
             int node=q.front();
             q.pop();
             ans.push_back(node);
             for (auto it:adj[node]){
                 indegree[it]--;
                 if(indegree[it]==1){
                     q.push(it);
                 }
             }
         }

    }
    if(n==1){
        ans.push_back(0);
    }
return ans;


    }
};