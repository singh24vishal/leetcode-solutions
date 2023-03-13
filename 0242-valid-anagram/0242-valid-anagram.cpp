class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1,mp2;
        for(auto e:s) mp1[e]++;
        for(auto e:t) mp2[e]++;
        return mp1==mp2;
    }
};