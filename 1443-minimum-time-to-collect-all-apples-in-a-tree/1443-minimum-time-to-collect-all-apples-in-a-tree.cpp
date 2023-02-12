class Solution {
public:
    int dfs(int v,int par,vector<vector<int>>&g,vector<bool>&app)
    {
        int c=0;
        for(auto e:g[v])
        {
            if(e!=par)
                c+=dfs(e,v,g,app);
        }
        if(c>0 or app[v]) return c+2;
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& app) {
        vector<vector<int>> g(n);
        for(auto e:edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return max(dfs(0,-1,g,app)-2,0);
    }
};