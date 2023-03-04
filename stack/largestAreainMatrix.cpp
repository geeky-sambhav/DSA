
// ALMOST SAME AS LARGEST AREA IN MATRIX 
// PEHLE FIRST ROW KA AREA NIKALNA FIR NICHE VALI RO WKO USKE SATH ADD KRNA FIR AREA NIKALNA
// AISE KRTE JAANA BT AGR BASE ROW 0 JAYE TO 0 KRDO
// AUR MAX LARGEST AREA OF RECTANGLE NIKAL LO

class Solution{
  public:
   int largestRectangleArea(int* heights,int n) {
        vector<int>ans;
        
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
    vector <int> nextSmaller(int* heights,int n){
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

    vector <int>previousSmaller(int* heights,int n){
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
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area=largestRectangleArea(M[0],m);
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                if(M[i][j]!=0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }
                else{
                     M[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(M[i],m));
        }
    return area;
    }
};
