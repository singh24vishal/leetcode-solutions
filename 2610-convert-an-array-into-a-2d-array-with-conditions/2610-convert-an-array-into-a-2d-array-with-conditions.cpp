class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int mx=0;
        map<int,int> mp;
        for(auto e:nums)
        {
            mp[e]++;
            mx=max(mx,mp[e]);
        }
        vector<vector<int>> ans(mx);
        for(auto e:mp)
        {
            int f=e.second;
            while(f>0)
            {
                ans[f-1].push_back(e.first);
                f--;
            }
        }
        return ans;
    }
};