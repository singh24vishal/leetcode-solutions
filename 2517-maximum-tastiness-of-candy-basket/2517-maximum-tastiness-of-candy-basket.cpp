class Solution {
public:
    bool fun(vector<int>v,int n,int k,int mid)
    {
        int prev=v[0],c=1;
        for(int i=1;i<n;i++)
        {
            if(v[i]-prev>=mid)
            {
                c++;
                prev=v[i];
            }
        }
        return c>=k;
    }
    int maximumTastiness(vector<int>& v, int k) {
        int n=v.size();
        sort(v.begin(),v.end());
        int ans=INT_MIN;
        int l=0,h=1e9+9;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(fun(v,n,k,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};