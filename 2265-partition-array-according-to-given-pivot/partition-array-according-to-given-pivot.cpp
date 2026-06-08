class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int l =0, r = n-1;
        for(int i = 0;i<n;i++){
            if(nums[i]<pivot){
                ans[l]=nums[i];
                l++;
            }
            if(nums[n-i-1]>pivot){
                ans[r]=nums[n-i-1];
                r--;
            }
        }
        if(l<=r){
            while(l<=r){
                ans[l]=pivot;
                l++;
            }
        }
        return ans;
    }
};