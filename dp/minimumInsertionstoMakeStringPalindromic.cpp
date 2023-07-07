
    #include <bits/stdc++.h> 

int minInsertion(string &str)

{

    // Write your code here.

    string str2 = str;

    reverse(str2.begin(), str2.end());

    int m = str.length();

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int i=1;i<=m;i++){

        for(int j=1;j<=m;j++){

            if(str[i-1]==str2[j-1]){

                curr[j]=1+prev[j-1];

            }else{

                curr[j]=max(prev[j], curr[j-1]);

            }

        }

        prev=curr;

    }

    return m-prev[m];

}
