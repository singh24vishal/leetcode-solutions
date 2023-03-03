class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        vector<int> temp=v[0];
        for(int i=1;i<v.size();i++)
        {
            vector<int> temp2(v[i].size());
            for(int j=0;j<v[i].size();j++)
            {
                temp2[j]=v[i][j];
                if(j==0) temp2[j]+=temp[0];
                else if(j>=temp.size()) temp2[j]+=temp.back();
                else temp2[j]+=min(temp[j],temp[j-1]);
            }
            temp=temp2;
        }
        int ans=INT_MAX;
        for(auto e:temp) ans=min(ans,e);
        return ans;
    }
};