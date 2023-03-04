class Solution {
public:
    vector <int> nextSmaller(vector<int> heights,int n){
        stack<int>s1;
        
        vector<int> ans(n);
        for (int i=n-1;i>=0;i--){
            while(!s1.empty() && (heights[i]<=heights[s1.top()])){
                s1.pop();
            }
            if(s1.empty()){

            ans[i]=n-1;
            }
            else{
                ans[i]=s1.top()-1;
            }
            s1.push(i);
        }

return ans;
    }

    vector <int>previousSmaller(vector<int> heights,int n){
        stack<int>s1;
        
        vector<int> ans(n);
        for (int i=0;i<n;i++){
            while(!s1.empty() && (heights[i]<=heights[s1.top()])){
                s1.pop();
            }
            if(s1.empty()){

            ans[i]=0;
            }
            else{
                ans[i]=s1.top()+1;
            }
            s1.push(i);
        }

return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>ans;
        int n=heights.size();
        vector<int>next(n);
        next=nextSmaller(heights,n);
        vector<int>previous(n);
        previous=previousSmaller(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            
            int b=next[i]-previous[i]+1;
            int newArea=(heights[i]*b);
             area = max(area, newArea);
        }
        return area;
    }
};