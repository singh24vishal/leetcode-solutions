class Solution {
public:
    vector<pair<int,int>> vp={{1,0},{-1,0},{0,1},{0,-1}};
    bool ok(int i,int j,int n,int m)
    {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>&v)
    {
        v[i][j]=0;
        for(auto [x,y]:vp)
        {
            int a=i+x,b=j+y;
            if(ok(a,b,n,m) and v[a][b]!=0)
                dfs(a,b,n,m,v);
        }
    }
    int numEnclaves(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(v[i][0]==1) dfs(i,0,n,m,v);
            if(v[i][m-1]==1) dfs(i,m-1,n,m,v);
        }
        for(int i=0;i<m;i++)
        {
            if(v[0][i]==1) dfs(0,i,n,m,v);
            if(v[n-1][i]==1) dfs(n-1,i,n,m,v);
        }
        c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) c+=v[i][j];
        }
        return c;
    }
};