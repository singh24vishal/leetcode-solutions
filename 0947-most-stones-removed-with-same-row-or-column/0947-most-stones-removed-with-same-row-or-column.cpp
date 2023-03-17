class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>>&v,int n)
    {
        vis[i]=1;
        for(int j=0;j<n;j++)
        {
            if(vis[j]) continue;
            if(v[i][0]==v[j][0] or v[i][1]==v[j][1]) dfs(j,vis,v,n);
        }
    }
    int removeStones(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> vis(n,0);
        int  c=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            dfs(i,vis,v,n);
            c++;
        }
        return n-c;
    }
};