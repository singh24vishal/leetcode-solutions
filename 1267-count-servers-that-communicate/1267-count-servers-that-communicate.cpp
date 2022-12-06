class Solution {
public:
    vector<int> par;
    vector<int> sz;
    void make(int i)
    {
        par[i]=i;
        sz[i]=1;
    }
    int find(int v)
    {
        if(v==par[v]) return v;
        return par[v]=find(par[v]);
    }
    void uni(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    void fun(int i,int j,int n,int m,vector<vector<int>>&v)
    {
        for(int x=i+1;x<n;x++)
        {
            if(v[x][j]>0) uni(v[i][j],v[x][j]);
        }
        for(int y=j+1;y<m;y++)
        {
            if(v[i][y]>0) uni(v[i][j],v[i][y]);
        }
    }
    int countServers(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        int c=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1) 
                {
                    v[i][j]=c;
                    c++;
                }
            }
        }
        par.resize(c);
        sz.resize(c);
        for(int i=1;i<c;i++) make(i);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]>0) fun(i,j,n,m,v);
            }
        }
        for(int i=1;i<c;i++)
        {
            if(find(i)==i and sz[i]>1) ans+=sz[i];
        }
        return ans;
    }
};