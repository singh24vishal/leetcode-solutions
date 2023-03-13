class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto e:s) mp[e]++;
        string ans="";
        vector<pair<int,char>> v;
        for(auto [x,y]:mp) v.push_back({y,x});
        sort(v.rbegin(),v.rend());
        for(auto [x,y]:v)
        {
            for(int i=0;i<x;i++) ans+=y;
        }
        return ans;
    }
};