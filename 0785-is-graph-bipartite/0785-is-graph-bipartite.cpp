class Solution {
public:
    void dfs(int node,vector<vector<int>>&g,vector<int>&vis,int col,bool &ans)
    {
        vis[node]=col;
        for(auto e:g[node])
        {
            if(vis[e]==0) dfs(e,g,vis,3-col,ans);
            else if(vis[e]==vis[node]) ans=false;
        }
    }
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        bool ans=true;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            dfs(i,g,vis,1,ans);
        }
        return ans;
    }
};