class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(int n : nums){
            maxi = max(maxi ,n);
            sum+=n;
        }
        int s = nums.size();
        return (s*maxi) - sum;
    }
};