class Solution {
public:
    long long int jump(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        long long int ans=1;
        int l=0,r=arr[0];
        while(r<n-1)
        {
            int tl=l;
            for(int i=r;i>tl;i--)
            {
                if(i+arr[i]>r)
                {
                    r=i+arr[i];
                    l=i;
                }
            }
            ans++;
        }
        return ans;
    }
};