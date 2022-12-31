class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<m;i++) dp[n-1][i]=v[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                int a=dp[i+1][j],b=INT_MAX,c=INT_MAX;
                if(j>0) b=dp[i+1][j-1];
                if(j<m-1) c=dp[i+1][j+1];
                dp[i][j]=min({a,b,c})+v[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++) ans=min(ans,dp[0][i]);
        return ans;
    }
};