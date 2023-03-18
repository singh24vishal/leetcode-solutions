class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        sort(v.begin(),v.end());
        string a=v[0],b=v.back();
        int idx=0;
        for(int i=0;i<min(a.size(),b.size());i++)
        {
            if(a[i]!=b[i]) break;
            idx=i+1;
        }
        string ans=a.substr(0,idx);
        return ans;
    }
};