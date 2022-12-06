class Solution {
public:
    int countServers(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<int> r(n,0),c(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1 and (r[i]>1 or c[j]>1)) ans++;
            }
        }
        return ans;
    }
};