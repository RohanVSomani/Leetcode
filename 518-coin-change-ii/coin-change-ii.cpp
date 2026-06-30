class Solution {
public:
    int helper(int amount , int i , vector<int> &coins,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i] == 0)
                return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int nottake = helper(amount,i-1,coins,dp);
        int take = 0;
        if(coins[i]<=amount)
        take = helper(amount-coins[i],i,coins,dp);
        return dp[i][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = helper(amount , coins.size()-1 , coins,dp);
        return ans;
    }
};