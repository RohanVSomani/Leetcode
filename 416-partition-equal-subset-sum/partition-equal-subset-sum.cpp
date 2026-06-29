class Solution {
public:
    bool helper(vector<int> ans, int i, int sum,vector<vector<int>> &dp){
        if(sum == 0)return true;
        if(i==0)return ans[i]==sum;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool dontake = helper(ans,i-1,sum,dp);
        bool take = false;
        if(ans[i]<=sum)
            take = helper(ans,i-1,sum-ans[i],dp);
        return dp[i][sum] = take || dontake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int n : nums) sum += n;
        
        if(sum%2!=0)return false;
        sum = sum/2;
        vector<int> prev(sum+1,false),cur(sum+1,false);
        prev[0] = true;
        if(nums[0]<=sum)
        prev[nums[0]] = true;
        for(int i =1;i<nums.size();i++){
            cur[0]=true;
            for(int tar = 1;tar<=sum;tar++){
                bool dontake = prev[tar];
                bool take = false;
                if(nums[i]<=tar)
                    take = prev[tar-nums[i]];
                cur[tar] = dontake || take;
            }
            prev = cur;
        }
        return prev[sum];
    }
};