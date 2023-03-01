class Solution {
public:
    int subsetXORSum(vector<int>& v) {
        int ans=0,l=pow(2,v.size()),n=v.size();
        for(int i=0;i<l;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j)) temp=temp^v[j];
            }
            ans+=temp;
        }
        return ans;
    }
};