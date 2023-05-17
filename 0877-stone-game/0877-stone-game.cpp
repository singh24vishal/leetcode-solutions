class Solution {
public:
    int fun(int i,int j,vector<int>&v,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]) return dp[i][j];
        int x=0,y=0;
        x=v[i]+min(fun(i+2,j,v,dp),fun(i+1,j-1,v,dp));
        y=v[j]+min(fun(i+1,j-1,v,dp),fun(i,j-2,v,dp));
        return dp[i][j]=max(x,y);
    }
    bool stoneGame(vector<int>& v) {
        int n=v.size();
        int i=0,j=n-1;
        int sum=accumulate(v.begin(),v.end(),0);
        vector<vector<int>> dp(n,vector<int>(n,0));
        fun(i,j,v,dp);
        return dp[0][n-1]*2>sum;
    }
};