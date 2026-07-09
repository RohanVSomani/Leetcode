class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy){
            int take = -prices[i] + helper(prices, i+1, 0, dp);
            int notTake = helper(prices, i+1, 1, dp);
            profit = max(take, notTake);
        }
        else{
            int take = prices[i] + helper(prices, i+1, 1, dp);
            int notTake = helper(prices, i+1, 0, dp);
            profit = max(take, notTake);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, dp);
    }
};