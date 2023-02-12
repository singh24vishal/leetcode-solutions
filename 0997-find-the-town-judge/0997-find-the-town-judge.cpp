class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        vector<int> vis(n+1,0);
        vector<int> c(n+1,0);
        for(auto e:v)
        {
            vis[e[0]]=1;
            c[e[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0 and c[i]==n-1) return i;
        }
        return -1;
    }
};