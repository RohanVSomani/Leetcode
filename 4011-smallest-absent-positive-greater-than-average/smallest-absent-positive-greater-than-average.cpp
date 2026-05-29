

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
       for(int n:nums){
        sum+=n;
       } 
       int sz = nums.size();
       int avg = sum/sz;
       if(avg<0)
       avg=1;
       else
       avg++;
       int i = 0;
       cout<<avg<<" "<<sum;
       sort(nums.begin(), nums.end());
       while(i < nums.size())
        {
            if(nums[i] < avg)
                ++i;
            else if(nums[i] == avg)
                ++avg;
            else if(nums[i] > avg)
                return avg;
        }
        return avg;
    }
};