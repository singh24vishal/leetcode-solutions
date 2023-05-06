class Solution {
public:
    int numRescueBoats(vector<int>& v, int l) {
        int n=v.size(),ans=0;
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        while(i<=j)
        {
            if(v[i]+v[j]<=l)
            {
                i++;
                j--;
            }
            else j--;
            ans++;
        }
        return ans;
    }
};