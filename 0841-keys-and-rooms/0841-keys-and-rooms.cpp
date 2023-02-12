class Solution {
public:
    void dfs(int i,vector<vector<int>>&v,vector<int>&vis)
    {
        vis[i]=1;
        for(auto e:v[i])
        {
            if(vis[e]==0) dfs(e,v,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> vis(n,0);
        dfs(0,v,vis);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) return false;
        }
        return true;
    }
};