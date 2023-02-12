class Solution {
public:
    vector<pair<int,int>> vp={{1,0},{0,1},{0,-1},{-1,0}};
    bool ok(int i,int j,int n,int m)
    {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>&v2,vector<vector<int>>&v1,int &c)
    {
        if(v1[i][j]==0)
        {
            c=0;
        }
        v2[i][j]=0;
        for(auto e:vp)
        {
            int x=i+e.first,y=j+e.second;
            if(ok(x,y,n,m) and v2[x][y]==1) dfs(x,y,n,m,v2,v1,c);
        }
    }
    int countSubIslands(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int n=v1.size(),m=v1[0].size();
        int ans=0,c=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v2[i][j]==1)
                {
                    dfs(i,j,n,m,v2,v1,c);
                    if(c==1) ans++;
                    c=1;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        return ans;
    }
};