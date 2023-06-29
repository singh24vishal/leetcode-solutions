class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return true;
        int mx=INT_MIN,mn=INT_MAX,a=1;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
            if(i>0 and nums[i]<nums[i-1]) a=0;
        }
        if(mx==mn) return true;
        if(nums[0]==mn and nums[n-1]==mx)
        {
            if(a) return true;
            return false;
        }
        vector<int> temp;
        int in=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==mx and nums[i+1]==mn) 
            {
                in=i;
                break;
            }
        }
        for(int i=in+1;i<n;i++) temp.push_back(nums[i]);
        for(int i=0;i<=in;i++) temp.push_back(nums[i]);
        for(int i=1;i<n;i++) if(temp[i]<temp[i-1]) return false;
        return true;
    }
};