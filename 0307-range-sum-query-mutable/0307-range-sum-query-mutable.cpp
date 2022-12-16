class NumArray {
public:
    vector<int> arr;
    vector<int> arr2;
     void cupdate(int in, int val) {
        in+=1;
         while(in<arr.size())
         {
             arr[in]+=val;
             in+=in&(-in);
         }
    }
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        arr.resize(n+1,0);
        arr2=nums;
        for(int i=0;i<n;i++) cupdate(i,nums[i]);
    }
    
    void update(int in,int val)
    {
        int e=val-arr2[in];
        arr2[in]=val;
        cupdate(in,e);
    }
    
    int sum(int l)
    {
        int x=0;
        while(l>0)
        {
            x+=arr[l];
            l-=l&(-l);
        }
        return x;
    }
    
    int sumRange(int l, int r) {
        l++;
        r++;
        return sum(r)-sum(l-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */