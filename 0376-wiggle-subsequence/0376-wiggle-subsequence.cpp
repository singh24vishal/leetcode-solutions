class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
        int ans=0;
        int inc=1,dec=1;
        for(int i=1;i<n;i++)
        {
            if(v[i]>v[i-1]) inc=dec+1;
            else if(v[i]<v[i-1]) dec=inc+1;
        }
        return max(inc,dec);
    }
};