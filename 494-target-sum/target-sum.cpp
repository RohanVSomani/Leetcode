class Solution {
public:

    int helper(int i,vector<int> &nums,int tar,int act){
        if(i==-1){
            if(tar == act)
            return 1;
            else return 0;
        }
        int minus = helper(i-1,nums,tar+nums[i],act);
        int plus = helper(i-1,nums,tar-nums[i],act);
        return minus+plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        //vector<vector<int>> dp(nums.size(),vector<int>(target+target,-1));
        int ans = helper(n-1,nums,0,target);
        //int ans = helper(n-1,coins,amount,dp);
        /*for(int i =0;i<=amount;i++){
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
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];*/
        return ans;
    }
};


    