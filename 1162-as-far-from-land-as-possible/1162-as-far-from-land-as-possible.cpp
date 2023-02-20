class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<pair<int,int>> a,b;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0) b.push_back({i,j});
                else a.push_back({i,j});
            }
        }
        int ans=-1;
        for(auto [x,y]:b)
        {
            int temp=INT_MAX;
            for(auto [i,j]:a)
                temp=min(temp,abs(i-x)+abs(j-y));
            if(temp!=INT_MAX)
                ans=max(ans,temp);
        }
        return ans;
    }
};