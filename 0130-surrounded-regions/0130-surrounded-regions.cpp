class Solution {
public:
    vector<pair<int,int>> vp={{-1,0},{0,-1},{1,0},{0,1}};
    bool safe(int i,int j,int n,int m)
    {
        return (i>=0 and i<n and j>=0 and j<m);
    }
    void dfs(int i,int j,vector<vector<char>>&v,int n,int m)
    {
        if(v[i][j]!='O') return;
        v[i][j]='*';
        for(auto [x,y]:vp)
        {
            int a=i+x,b=y+j;
            if(safe(a,b,n,m)) dfs(a,b,v,n,m);
        }
    }
    void solve(vector<vector<char>>& v) {
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++) 
        {
            if(v[i][0]=='O') dfs(i,0,v,n,m);
            if(v[i][m-1]=='O') dfs(i,m-1,v,n,m);
        }
        for(int j=0;j<m;j++)
        {
            if(v[0][j]=='O') dfs(0,j,v,n,m);
            if(v[n-1][j]=='O') dfs(n-1,j,v,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='O') v[i][j]='X';
                if(v[i][j]=='*') v[i][j]='O';
            }
        }
    }
};