class Solution {
public:
    void dfs1(int node,int pr,vector<int>&par,vector<vector<int>>&g,int &dist,int cur,int bob)
    {
        par[node]=pr;
        if(node==bob) dist=cur;
        for(auto e:g[node])
        {
            if(e!=pr) dfs1(e,node,par,g,dist,cur+1,bob);
        }
    }
    void fun(int bob,int f,int dist,vector<int>&par,vector<int>&amount)
    {
        int cur=0;
        while(cur<dist)
        {
            amount[bob]=0;
            bob=par[bob];
            cur++;
        }
        if(f) amount[bob]/=2;
    }
    void dfs2(int node,int par,vector<vector<int>>&g,vector<int>&amount,int cur,int &c)
    {
        cur+=amount[node];
        for(auto e:g[node])
        {
            if(e!=par) dfs2(e,node,g,amount,cur,c);
        }
        if(g[node].size()==1 and node!=0)
        {
            c=max(c,cur);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>> g(n);
        for(auto e:edges)
        {
            int x=e[0],y=e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> par(n);
        int dist=0;
        dfs1(0,-1,par,g,dist,0,bob);
        int f=0;
        if(dist%2==0) f=1;
        dist=(dist+1)/2;
        fun(bob,f,dist,par,amount);
        int c=INT_MIN;
        dfs2(0,-1,g,amount,0,c);
        // for(auto  e:amount) cout<<e<<" ";
        return c;
    }
};