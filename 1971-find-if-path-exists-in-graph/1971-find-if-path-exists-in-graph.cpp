class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> g[n];
        for(auto e:edges) 
        {
            int u=e[0],v=e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q;
        vector<int> vis(n,0);
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            if(t==dest) return true;
            for(auto e:g[t])
            {
                if(vis[e]==0)
                {
                    q.push(e);
                    vis[e]=1;
                }
            }
        }
        return false;
    }
};