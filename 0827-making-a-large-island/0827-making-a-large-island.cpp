class Solution {
public:
    vector<pair<int,int>> vp={{0,1},{0,-1},{1,0},{-1,0}};
    bool ok(int i,int j,int n,int m)
    {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>&v,int &c)
    {
        c++;
        v[i][j]=-1;
        for(auto [a,b]:vp)
        {
            int x=i+a,y=j+b;
            if(ok(x,y,n,m) and v[x][y]==1) dfs(x,y,n,m,v,c);
        }
    }
    void dfs2(int i,int j,int n,int m,vector<vector<pair<int,int>>>&dp,int c,int x)
    {
        dp[i][j].first=c;
        dp[i][j].second=x;
        for(auto [a,b]:vp)
        {
            int y=i+a,z=j+b;
            if(ok(y,z,n,m) and dp[y][z].first==1) dfs2(y,z,n,m,dp,c,x);
        }
    }
    int largestIsland(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m,{0,0}));
        int x=1;
        vector<pair<int,int>> zero;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) 
            {
                if(v[i][j]==0) zero.push_back({i,j});
                dp[i][j].first=v[i][j];
            }
        }
        if(zero.size()==0) return n*m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==-1 or v[i][j]==0) continue;
                else 
                {
                    int c=0;
                    dfs(i,j,n,m,v,c);
                    dfs2(i,j,n,m,dp,c,x);
                    x++;
                }
            }
        }
        int mx=0;
        for(auto [i,j]:zero)
        {
            int cur=0;
            map<int,int> mp;
            for(auto [a,b]:vp)
            {
                int c=i+a,d=j+b;
                if(ok(c,d,n,m) and !mp[dp[c][d].second])
                {
                    cur+=dp[c][d].first;
                    mp[dp[c][d].second]=1;
                }
            }
            mx=max(mx,cur+1);
        }
        return mx;
    }
};