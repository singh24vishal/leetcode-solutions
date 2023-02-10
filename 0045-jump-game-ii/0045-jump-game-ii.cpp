class Solution {
public:
    long long int jump(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        long long int ans=1;
        int l=0,r=arr[0],cur=0;
        while(r<n-1)
        {
            for(int i=r;i>=0;i--)
            {
                r=max(r,i+arr[i]);
            }
            // cout<<r<<" ";
            ans++;
        }
        return ans;
    }
};