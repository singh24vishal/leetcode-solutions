class Solution {
public:
    void dfs(int node,vector<vector<int>>&g,vector<int>&vis,vector<int>&v)
    {
        if(vis[node]) return;
        vis[node]=1;
        v.push_back(node);
        for(auto e:g[node]) dfs(e,g,vis,v);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<vector<int>> g(n+1);
        vector<int> vis(n+1,0);
        for(auto e:pairs) {g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]);}
        string ans=s;
        vector<vector<int>> con;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            dfs(i,g,vis,v);
            if(v.size()>0) con.push_back(v);
        }
        for(auto e:con)
        {
            string temp="";
            int sz=e.size();
            for(int i=0;i<sz;i++) temp+=s[e[i]];
            sort(e.begin(),e.end());
            sort(temp.begin(),temp.end());
            for(int i=0;i<sz;i++)
            ans[e[i]]=temp[i];
            // for(auto i:e) cout<<i<<" "; cout<<endl;
        }
        return ans;
    }
};