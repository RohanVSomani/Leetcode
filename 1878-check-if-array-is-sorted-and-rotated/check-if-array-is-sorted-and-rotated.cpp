class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0,last=nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                last=nums[0];
                cnt++;
            }
            if(cnt==1&&last<nums[i]){
                return false;
            }
        }
        if(cnt<=1)
         return true;
        return false;

    }
};