class Solution {
public:
    int maxProduct(vector<int>& v) {
        int ans=INT_MIN,n=v.size();
        for(int i=0;i<n;i++)
        {
            int temp=1;
            for(int j=i;j<min(i+32,n);j++)
            {
                temp=temp*v[j];
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};