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
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        //int ans = helper(n-1,coins,amount,dp);
        for(int i =0;i<=amount;i++){
        if(i%coins[0] == 0)dp[0][i] = i/coins[0];
        else
        dp[0][i] = 1e9;
        }

        for(int i = 1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int nottake = 0+dp[i-1][j];
                int take = 1e9;
                if(coins[i]<=j)
                    take = dp[i][j-coins[i]]+1;
                dp[i][j] = min(take,nottake);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
};