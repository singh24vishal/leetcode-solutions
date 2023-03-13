class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(auto e:s) v1[e-'a']++;
        for(auto e:t) v2[e-'a']++;
        return v1==v2;
    }
};