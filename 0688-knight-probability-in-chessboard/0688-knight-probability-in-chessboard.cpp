class Solution {
public:
    vector<pair<int,int>> vp={{-2,-1},{-2,1},{2,1},{2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    bool ok(int i,int j,int n)
    {
        return (i>=0 and j>=0 and i<n and j<n);
    }
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<double>> dp(n,vector<double>(n,0.0));
        dp[r][c]=1;
        while(k--)
        {
            vector<vector<double>> dp2(n,vector<double>(n,0.0));
            for(int  i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dp[i][j]>0)
                    {
                        double xx=dp[i][j]/8.0;
                        for(auto [x,y]:vp)
                        {
                            int a=i+x,b=j+y;
                            if(ok(a,b,n)) dp2[a][b]+=xx;
                        }
                    }
                }
            }
            dp=dp2;
        }
        double ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) ans+=dp[i][j];
        }
        return ans;
    }
};