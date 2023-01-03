class Solution {
public:
    bool fun(vector<int>&v,int n,int mx)
    {
        if(v[1]-v[0]>mx or v[n-1]-v[n-2]>mx) return false;
        for(int i=2;i<n;i+=2)
        {
            if(v[i]-v[i-2]>mx) return false;
        }
        for(int i=3;i<n;i+=2)
        {
            if(v[i]-v[i-2]>mx) return false;
        }
        return true;
    }
    int maxJump(vector<int>& v) {
        int l=0,h=1e9;
        int ans=INT_MAX,n=v.size();
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(fun(v,n,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};