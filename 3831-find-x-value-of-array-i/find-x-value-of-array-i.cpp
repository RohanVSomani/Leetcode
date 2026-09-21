class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k), state(k);
        for (int value : nums) {
            int rem = value % k;
            vector<long long> next(k);
            for (int r = 0; r < k; r++) {
                int remtemp = (r * rem) % k;
                next[remtemp] += state[r];
                result[remtemp] += state[r];
            }
            next[rem]++;
            result[rem]++;
            state = next;
        }
        return result;
    }
};