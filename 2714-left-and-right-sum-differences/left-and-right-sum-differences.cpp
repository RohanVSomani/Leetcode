class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> lsum(nums.size(),0), rsum(nums.size(),0);
        int lsum1= 0, rsum1 = 0;
        for(int i = 0 ;i<nums.size();i++){
            int lindex = i;
            int rindex = nums.size()-i-1;
            lsum1 += nums[lindex];
            rsum1 += nums[rindex];
            lsum[lindex]=lsum1;
            rsum[rindex]=rsum1;
        }
        vector<int> ans;
        for(int i =0;i<lsum.size();i++){
            ans.push_back(abs(lsum[i]-rsum[i]));
        }
        return ans;
    }
};