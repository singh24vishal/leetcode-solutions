class Solution {
public:
    void dfs(int v,int par,int n,vector<vector<int>>&ans,vector<int>&temp,vector<vector<int>>&g)
    {
        temp.push_back(v);
        if(v==n)
        {
            ans.push_back(temp);
            return;
        }
        for(auto e:g[v])
        {
            if(e!=par)
            {
                dfs(e,v,n,ans,temp,g);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0,-1,g.size()-1,ans,temp,g);
        return ans;
    }
};