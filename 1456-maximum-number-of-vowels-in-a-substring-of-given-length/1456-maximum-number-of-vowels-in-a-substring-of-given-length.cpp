class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        vector<char> v={'a','e','i','o','u'};
        int i=0,j=0,mx=0,n=s.size();
        while(j<n and j<k)
        {
            for(auto e:v)
            {
                if(e==s[j]) ans++;
            }
            mx=max(mx,ans);
            j++;
        }
        while(j<n)
        {
            for(auto e:v)
            {
                if(e==s[j]) ans++;
            }
            for(auto e:v)
            {
                if(e==s[i]) ans--;
            }
            i++;
            j++;
            mx=max(mx,ans);
        }
        return mx;
    }
};