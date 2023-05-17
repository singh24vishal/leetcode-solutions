class Solution {
public:
    int fun(int i,int j,vector<vector<int>> &dp,int n,vector<int> &v,int c)
    {
        if(i>=n or j<0 or i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=fun(i+1,j,dp,n,v,1-c);
        int b=fun(i,j-1,dp,n,v,1-c);
        int x1=v[i]+a;
        int x2=v[j]+b;
        if(c==0) dp[i][j]=max(x1,x2);
        else dp[i][j]=min(a,b);
        return dp[i][j];
    }
    bool stoneGame(vector<int>& v) {
        int n=v.size();
        int sum=accumulate(v.begin(),v.end(),0);
        vector<vector<int>> dp(n,vector<int>(n,-1));
		int ans=fun(0,n-1,dp,n,v,0);
        return 2*ans>sum;
    }
};