class Solution {
public:
    vector<pair<int,int>> vp={{0,1},{0,-1},{1,0},{-1,0}};
    bool ok(int i,int j,int n,int m)
    {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    int minCost(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        map<pair<int,int>,int> mp;
        vector<vector<int>> dp(n,vector<int>(m,1000));
        queue<pair<int,int>> q;
        q.push({0,0});
        dp[0][0]=0;
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            int i=temp.first,j=temp.second;
            for(auto e:vp)
            {
                int x=i+e.first,y=j+e.second;
                if(ok(x,y,n,m))
                {
                    int c=0;
                    if(e!=vp[v[i][j]-1]) c=1;
                    if(dp[x][y]>dp[i][j]+c)
                    {
                        dp[x][y]=dp[i][j]+c;
                        q.push({x,y});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};