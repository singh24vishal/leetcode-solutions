class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> mp1,mp2;
        int c=0,n=s.size();
        vector<int> v3(n);
        vector<int> v4(n);
        for(int i=0;i<n;i++) 
        {
            if(!mp1[s[i]-'0']) mp1[s[i]-'0']=++c;
            v3[i]=mp1[s[i]-'0'];
        }
        c=0;
        for(int i=0;i<n;i++) 
        {
            if(!mp2[t[i]-'0']) mp2[t[i]-'0']=++c;
            v4[i]=mp2[t[i]-'0'];
        }
        for(int i=0;i<n;i++) 
        {
            if(v3[i]!=v4[i]) return false;
        }
        return true;
    }
};