class Solution {
public:
    void dfs(int v,vector<vector<int>>&g,vector<int>&vis)
    {
        vis[v]=1;
        for(auto e:g[v])
        {
            if(vis[e]==0) dfs(e,g,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> g(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(adj[i][j]==1)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i,g,vis);
            }
        }
        return ans;
    }
};