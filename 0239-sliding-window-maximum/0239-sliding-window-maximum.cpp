class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> ans;
        int n=v.size();
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)
        {
            a[i]=v[i];
            if(i%k) a[i]=max(a[i],a[i-1]);
        }
        b[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            b[i]=v[i];
            if(i%k!=k-1) b[i]=max(b[i],b[i+1]);
        }
        for(int i=0;i<n-k+1;i++) ans.push_back(max(b[i],a[i+k-1]));
        return ans;
    }
};