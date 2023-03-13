class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st=0,en=nums.size()-1;
        while(st<en)
        {
            int mid=(st+en)/2;
            if(mid%2) mid--;
            if(nums[mid]==nums[mid+1]) st=mid+2;
            else en=mid;
        }
        return nums[en];
    }
};