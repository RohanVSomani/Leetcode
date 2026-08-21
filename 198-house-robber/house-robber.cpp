class Solution {
public:
    int helper(vector<int> &nums, int i,vector<int> &dp){
        if(i<0)
        return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + helper(nums, i-2, dp);
        int nottake = 0 + helper(nums, i-1, dp);
        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int amt = helper(nums,nums.size()-1,dp);
        return amt;
    }
};