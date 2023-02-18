class Solution {
public:
    vector<pair<int,int>> vp={{1,0},{-1,0},{0,1},{0,-1}};
    bool ok(int i,int j,int n,int m)
    {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>&v)
    {
        v[i][j]=-1;
        for(auto e:vp)
        {
            int x=i+e.first;
            int y=j+e.second;
            if(ok(x,y,n,m) and v[x][y]==1)
                dfs(x,y,n,m,v);
        }
    }
    int shortestBridge(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++)
        {
            int f=0;
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                   f=1;
                    dfs(i,j,n,m,v);
                    break;
                }
            }
            if(f) break;
        }
        queue<vector<int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==-1)
                {
                    q.push({i,j,0});
                }
            }
        }
        int ans=INT_MAX;
        while(!q.empty())
        {
            vector<int> temp=q.front();
            int i=temp[0],j=temp[1],dis=temp[2];
            q.pop();
            if(v[i][j]==2)
            {
                ans=dis-1;
                break;
            }
            for(auto e:vp)
            {
                int x=i+e.first;
                int y=j+e.second;
                if(ok(x,y,n,m) and v[x][y]!=-1 and v[x][y]!=2)
                {
                    if(v[x][y]==0)
                    {
                        v[x][y]=-1;
                        q.push({x,y,dis+1});
                    }
                    else 
                    {
                        v[x][y]=2;
                        q.push({x,y,dis+1});
                    }
                }
            }
        }
        return ans;
    }
};