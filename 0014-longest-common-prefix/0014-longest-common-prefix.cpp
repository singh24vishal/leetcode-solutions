class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int n=v.size();
        map<string,int> mp;
        string ans="";
        for(auto e:v)
        {
            string temp="";
            for(auto j:e)
            {
                temp+=j;
                mp[temp]++;
            }
        }
        for(auto [x,y]:mp)
        {
            if(y==n and x.size()>ans.size()) ans=x;
        }
        return ans;
    }
};