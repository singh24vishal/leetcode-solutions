class Solution {
public:
    bool ok(int i,int j,int n,int m)
    {
        return (i>=0 and i<n and j>=0 and j<m);
    }
    int maxDistance(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1) q.push({i,j});
            }
        }
        if(q.size()==0 or q.size()==n*m) return -1;
        int ans=-1;
        vector<pair<int,int>> vp={{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size())
        {
            ans++;
            int temp=q.size();
            for(int i=0;i<temp;i++)
            {
                auto [x,y]=q.front();
                q.pop();
                for(auto [a,b]:vp)
                {
                    int c=x+a,d=y+b;
                    if(ok(c,d,n,m) and v[c][d]==0)
                    {
                        q.push({c,d});
                        v[c][d]=1;
                    }
                }
            }
        }
        return ans;
    }
};