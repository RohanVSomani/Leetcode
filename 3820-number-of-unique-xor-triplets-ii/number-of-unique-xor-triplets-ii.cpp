class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        const int M = 2048;
        vector<bool> ans(M, false);
        vector<bool> seen(M, false);
        vector<bool> xorPair(M, false);
        for (int j = 0; j < n; j++) {

            for (int x = 0; x < M; x++) {
                if (seen[x]) {
                    xorPair[nums[j] ^ x] = true;
                }
            }
            xorPair[nums[j] ^ nums[j]] = true;

            seen[nums[j]] = true;
        }
        for (int k = 0; k < n; k++) {
            for (int x = 0; x < M; x++) {
                if (xorPair[x]) {
                    ans[x ^ nums[k]] = true;
                }
            }
        }
        return count(ans.begin(), ans.end(), true);
    }
};