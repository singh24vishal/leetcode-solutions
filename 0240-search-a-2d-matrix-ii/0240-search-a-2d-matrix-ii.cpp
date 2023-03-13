class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int n=v.size(),m=v[0].size();
        int st=0,en=m-1;
        while(st<n and en>=0)
        {
            int mid=v[st][en];
            if(mid==k) return true;
            else if(mid>k) en--;
            else st++;
        }
        return false;
    }
};