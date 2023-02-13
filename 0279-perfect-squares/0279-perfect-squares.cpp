class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i*i<=n;i++) v.push_back(i*i);
        int nn=v.size();
        vector<vector<int>> dp(nn+1,vector<int>(n+1,INT_MAX-1));
        for(int i=0;i<=nn;i++) dp[i][0]=0;
        for(int i=1;i<=nn;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(v[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-v[i-1]]+1);
            }
        }
        return dp[nn][n];
    }
};