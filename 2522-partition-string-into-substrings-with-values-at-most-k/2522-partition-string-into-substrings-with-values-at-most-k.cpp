#define ll long long
class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans=1;
        ll num=0;
        for(auto e:s)
        {
            int a=e-'0';
            if(a>k)
            {
                ans=-1;
                break;
            }
            num=num*10+a;
            if(num>k)
            {
                ans++;
                num=a;
            }
        }
        return ans;
    }
};