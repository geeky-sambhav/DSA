class NodeValue{
    public:
    int minValue;
    int maxValue;
    int size;
    NodeValue(int minValue,int maxValue,int size){
            this->minValue=minValue;
            this->maxValue=maxValue;
            this->size=size;
            }
    };

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue solve(Node* root){
        if(!root) return (NodeValue(INT_MAX,INT_MIN,0));
        auto left=solve(root->left);
        auto right=solve(root->right);
        if(left.maxValue<root->data && root->data<right.minValue){
                return NodeValue(min(root->data,left.minValue),
                max(root->data,right.maxValue),
                1+left.size+right.size);
            
        }
        else{
            return NodeValue(INT_MIN,INT_MAX,
            max(left.size,right.size));
        }
    }
    
    
    int largestBst(Node *root)
    {
    	return solve(root).size;
    }
};