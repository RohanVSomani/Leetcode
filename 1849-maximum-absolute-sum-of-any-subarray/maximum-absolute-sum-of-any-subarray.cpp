        class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int n = nums.size();
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int maxS = nums[0];
        int minS = nums[0];
        
        for (int i = 1; i < n; i++) {
            maxEnd = max(nums[i], maxEnd + nums[i]);
            minEnd = min(nums[i], minEnd + nums[i]);
            maxS= max(maxS, maxEnd);
            minS = min(minS, minEnd);
        }
        return max(abs(maxS), abs(minS));
    }
};