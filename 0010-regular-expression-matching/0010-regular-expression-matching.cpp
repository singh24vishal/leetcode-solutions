class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=0;i<m;i++)
        {
            if(p[i]=='*') dp[i+1][0]=dp[i-1][0];
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[i-1]=='*')
                {
                    if(dp[i-2][j]) dp[i][j]=true;
                    else if(p[i-2]==s[j-1] or p[i-2]=='.') dp[i][j]=dp[i][j-1];
                    else dp[i][j]=false;
                }
                else if(s[j-1]==p[i-1] or p[i-1]=='.') dp[i][j]=dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};