class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0, minnum = INT_MAX;
        for(int i=0;i<n;i++){
            minnum = min(minnum,prices[i]);
            if(prices[i]-minnum > maxProfit){
                maxProfit = prices[i]-minnum;
            }
        }
        return maxProfit;
    }
};
