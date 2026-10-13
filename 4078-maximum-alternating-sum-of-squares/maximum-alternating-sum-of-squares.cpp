class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs((long long)a) < abs((long long)b);
        });
        int l = 0, r = nums.size() - 1;
        long long score = 0;
        while (l < r) {
            score += 1LL * nums[r] * nums[r]
                   - 1LL * nums[l] * nums[l];
            l++;
            r--;
        }
        if (l == r)
            score += 1LL * nums[l] * nums[l];
        return score;
    }
};