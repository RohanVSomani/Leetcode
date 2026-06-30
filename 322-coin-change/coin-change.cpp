class Solution {
public:
    int helper(int i,vector<int> &coins,int amt,vector<vector<int>> &dp){
        if(i==0){
            if(amt%coins[i] == 0)return amt/coins[i];
            else return 1e9;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];
        int notake = 1e9;
        int take = 0 + helper(i-1,coins,amt,dp);
        if(coins[i]<=amt){
            notake = 1 + helper(i,coins,amt-coins[i],dp);
        }
        return dp[i][amt] = min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = helper(n-1,coins,amount,dp);
        return ans==1e9?-1:ans;
    }
};