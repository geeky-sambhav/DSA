LEVEL ORDER TRAVERSAL USE HOGA SINCE HM EK EK LEVEL TRAVERSE KR RHE
1 FOR LOOP MEIN 1 LEVEL PROCESS HOTA AUR DUSRE KE ELEMENTS AATE
EK TEMPERORARY ARRAY LENGE

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	queue<Node*>q;
    	vector<int>result;
        if(root==NULL){
            return result;
        }
    	bool leftToRight=true;
    	q.push(root);
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> ans(size);
    	    for (int i=0;i<size;i++){
    	   Node* front=q.front();
    	    q.pop();
    	        int index=leftToRight?i:size-i-1;
    	        ans[index]=front->data;
    	        if(front->left){
    	            q.push(front->left);
    	        }    
    	        if(front->right){
    	            q.push(front->right);
    	        }    
    	    }
    	    leftToRight=!leftToRight;
    	for(auto i:ans){
    	    result.push_back(i);
    	    
    	}
    	}
    	return result;
    }
};