class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string temp="";
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++)
            {
                temp+=s[j];
                mp[s[j]]++;
                int x=INT_MIN,y=INT_MAX;
                for(auto [a,b]:mp)
                {
                    x=max(x,b);
                    y=min(y,b);
                }
                ans+=x-y;
            }
        }
        return ans;
    }
};