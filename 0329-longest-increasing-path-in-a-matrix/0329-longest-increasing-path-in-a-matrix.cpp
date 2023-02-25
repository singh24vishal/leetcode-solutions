class Solution {
public:
    vector<pair<int,int>> vp={{1,0},{-1,0},{0,1},{0,-1}};
    bool ok(int i,int j,int n,int m)
    {
        return (i>=0 and i<n and j>=0 and j<m);
    }
    int dfs(int i,int j,vector<vector<int>>&v,vector<vector<int>>&dp,int n,int m)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(auto [x,y]:vp)
        {
            int a=i+x,b=j+y;
            if(ok(a,b,n,m) and v[a][b]>v[i][j])
                ans=max(ans,dfs(a,b,v,dp,n,m));
        }
        return dp[i][j]=ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==-1) ans=max(ans,dfs(i,j,v,dp,n,m));
            }
        }
        return ans;
    }
};