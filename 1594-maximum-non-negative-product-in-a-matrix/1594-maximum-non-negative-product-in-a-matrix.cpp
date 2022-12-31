#define ll long long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& v) {
        ll n=v.size(),m=v[0].size(), mod=1e9+7;
        vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(m));
        dp[0][0].first=dp[0][0].second=v[0][0];
        for(int i=1;i<m;i++) dp[0][i].first=dp[0][i].second=(1LL*v[0][i]*dp[0][i-1].first);
        for(int i=1;i<n;i++) dp[i][0].first=dp[i][0].second=(1LL*v[i][0]*dp[i-1][0].first);
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j].second=max(dp[i-1][j].second,dp[i][j-1].second)*v[i][j];
                dp[i][j].first=min(dp[i-1][j].first,dp[i][j-1].first)*v[i][j];
                if(dp[i][j].first>dp[i][j].second) swap(dp[i][j].first,dp[i][j].second);
            }
        }
        if(dp[n-1][m-1].second<0) return -1;
        return dp[n-1][m-1].second%mod;
    }
};