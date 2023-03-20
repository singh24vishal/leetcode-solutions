class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int> dp;
        dp[0]=0;
        for(auto e:rods)
        {
            unordered_map<int,int> cur=dp;
            for(auto it:cur)
            {
                int d=it.first;
                dp[d+e]=max(dp[d+e],cur[d]);
                dp[abs(d-e)]=max(dp[abs(d-e)],cur[d]+min(d,e));
            }
        }
        return dp[0];
    }
};