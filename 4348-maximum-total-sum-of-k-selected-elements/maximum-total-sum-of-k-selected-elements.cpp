class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        int cnt = k;
        long long sum = 0;
        while(cnt--){
            long long num = (long long)nums[i];
            i--;
            if(mul!=0){
                sum = sum + (long long)(mul*num);
                mul--;
            }
            else
                sum+=num;
        }
        return sum;
    }
};