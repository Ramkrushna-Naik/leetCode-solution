class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= profit.size();
        vector<int> dp(n+1,0);
        
        vector<pair<pair<int,int>, int> > store;
        
		//Sort on the basis of endTime
        for(int i=0;i<n;i++)
            store.push_back(make_pair(make_pair(endTime[i], startTime[i]), profit[i]));
        
        sort(store.begin(), store.end());
        
        dp[1] = store[0].second;
        
        for(int i=1;i<n;i++) {
            
            int j=i-1;
            
            while(j>=0 && store[i].first.second < store[j].first.first)  //Find previous index whose endTime is less than current index startTime
                j--;
            
            dp[i+1] = max(dp[i], j!=-1 ? store[i].second + dp[j+1] : store[i].second);   //Either include or exclude current index profit
        }
            
        return dp[n];
    }
};