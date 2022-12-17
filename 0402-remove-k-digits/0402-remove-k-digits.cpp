class Solution {
public:
    string removeKdigits(string s, int k) {
        vector<int> v;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(v.size()==0) v.push_back(s[i]-'0');
            else 
            {
                int x=s[i]-'0';
                while(v.size()>0 and k>0 and v.back()>x)
                {
                    v.pop_back();
                    k--;
                }
                v.push_back(x);
            }
        }
        while(k>0)
        {
            v.pop_back();
            k--;
        }
        string ans;
        int i=0;
        while(i<v.size() and v[i]==0) i++;
        for(int j=i;j<v.size();j++)
        {
            ans.push_back(v[j]+'0');
        }
        if(ans.size()==0) return "0";
        return ans;
    }
};