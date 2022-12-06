class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()==0) return 0;
        sort(v.begin(),v.end());
        int ans=1,c=1,n=v.size();
        int last=v[0];
        for(int i=1;i<n;i++)
        {
            if(v[i]==last) continue;
            if(v[i]==last+1)
            {
                c++;
                last=v[i];
            }
            else if(v[i]>last+1)
            {
                c=1;
                last=v[i];
            }
            ans=max(ans,c);
        }
        return ans;
    }
};