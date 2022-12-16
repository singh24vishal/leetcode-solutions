class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> v(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1]+arr[i-1][j-1];
        }
        pre=v;
    }
    
    int sumRegion(int a, int b, int c, int d) {
        return (pre[c+1][d+1]-pre[c+1][b]-pre[a][d+1]+pre[a][b]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */