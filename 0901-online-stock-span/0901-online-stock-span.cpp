class StockSpanner {
public:
    vector<pair<int,int>> v;
    map<pair<int,int>,int> mp;
    int i=0;
    StockSpanner() {
        v.push_back({INT_MAX,0});
        mp[v.back()]=0;
    }
    
    int next(int p) {
        i++;
        while((v.back()).first<=p)
        {
            v.pop_back();
        }
        int ans=i-mp[v.back()];
        v.push_back({p,i});
        mp[v.back()]=i;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */