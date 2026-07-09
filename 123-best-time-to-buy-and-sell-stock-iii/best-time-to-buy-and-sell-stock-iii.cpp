class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, int cap, vector<vector<vector<int>>> &dp){
        if(cap==0)return 0;
        if(i == prices.size()) return 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;

        if(buy){
            int take = -prices[i] + helper(prices, i+1, 0,cap, dp);
            int notTake = helper(prices, i+1, 1,cap, dp);
            profit = max(take, notTake);
        }
        else{
            int take = prices[i] + helper(prices, i+1, 1,cap-1, dp);
            int notTake = helper(prices, i+1, 0,cap, dp);
            profit = max(take, notTake);
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return helper(prices, 0, 1, 2, dp);
    }
};