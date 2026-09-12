class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2)
        return n;
        int maxi = nums[0] , mini=nums[0];
        int maind = 0, miind = 0;
        for(int i = 1;i < n; i++){
            int num = nums[i];
            if(num>maxi){
                maxi = num;
                maind = i;
            }
            if(num<mini){
                mini = num;
                miind = i;
            }
        }
        int ans = min({max(maind,miind)+1, max(n-maind,n-miind) , min({n-miind+maind+1,n-maind+miind+1})});
        return ans;
    }
};