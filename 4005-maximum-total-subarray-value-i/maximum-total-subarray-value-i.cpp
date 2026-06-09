class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = INT_MAX , maxi = INT_MIN;
        for(int n : nums){
            mini = min(mini,(long long)n);
            maxi = max(maxi,(long long)n);
        }
        return (maxi-mini)*k;
    }
};