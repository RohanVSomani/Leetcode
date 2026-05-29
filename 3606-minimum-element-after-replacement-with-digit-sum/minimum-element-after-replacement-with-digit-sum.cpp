class Solution {
public:
    int sumDigits(int num){
        int sum = 0;
        while(num!=0){
            int rem = num%10;
            sum+=rem;
            num=num/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int n : nums){
            mini = min(mini , sumDigits(n));
        }
        return mini;
    }
};