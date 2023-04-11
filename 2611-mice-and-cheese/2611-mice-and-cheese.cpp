class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        vector<vector<int>> v;
        int n=r1.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({r1[i]-r2[i],r1[i],r2[i]});
        }
        sort(v.rbegin(),v.rend());
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i<k) sum+=v[i][1];
            else sum+=v[i][2];
        }
        // for(auto e:v) cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
        return sum;
    }
};