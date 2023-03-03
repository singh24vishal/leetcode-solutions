class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(v[i][j]=='0') dp[i][j]=0;
                else dp[i][j]=min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]})+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) ans=max(ans,dp[i][j]*dp[i][j]);
        }
        return ans;
    }
};