class Solution {
public:
void DFS(Node* node,Node* clone_node,unordered_map<Node*,Node*>&mp){
    mp[node]=clone_node;
    for(Node* n:node->neighbors){
        if(mp.find(n)==mp.end()){
            Node* clone=new Node(n->val);
            mp[n]=clone;
            clone_node->neighbors.push_back(clone);
            DFS(n,clone,mp);
        }
        else{
              clone_node->neighbors.push_back(mp[n]);
        }
    }
}
    Node* cloneGraph(Node* node) {

        if(!node){
            return NULL;
        }
        Node* clone_node=new Node(node->val);
        unordered_map<Node*,Node*>mp;
        DFS(node,clone_node,mp);
        return clone_node;
    }
};


// WHY HASHMAP 
// TO STORE WHICH NODES HAVE BEEN CLONED