class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int n=v.size(),m=v[0].size();
        int st=0,en=n*m-1;
        while(st<=en)
        {
            int mid=(st+en)/2;
            int x=mid/m,y=mid%m;
            if(v[x][y]==k) return true;
            else if(v[x][y]>k) en=mid-1;
            else st=mid+1;
        }
        return false;
    }
};