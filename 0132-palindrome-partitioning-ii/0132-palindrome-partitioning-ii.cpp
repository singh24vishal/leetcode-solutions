class Solution {
public:
    bool pal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(string &s,int idx,vector<int>&dp,int n)
    {
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX;
        for(int i=idx;i<n;i++)
        {
            if(pal(s,idx,i)) ans=min(ans,1+solve(s,i+1,dp,n));
        }
        return dp[idx]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp,n)-1;
    }
};