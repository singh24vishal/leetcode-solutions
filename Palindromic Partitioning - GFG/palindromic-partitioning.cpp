//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool pal(string &str,int i,int j)
    {
        while(i<j)
        {
            if(str[i++]!=str[j--]) return false;
        }
        return true;
    }
    int solve(string &str,int idx,vector<int>&dp,int n)
    {
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX;
        for(int i=idx;i<n;i++)
        {
            if(pal(str,idx,i)) ans=min(ans,1+solve(str,i+1,dp,n));
        }
        return dp[idx]=ans;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        vector<int> dp(n,-1);
        return solve(str,0,dp,n)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends