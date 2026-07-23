class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int orAll = 0;
        for(int n:nums){
            orAll |= n;
        }
        return orAll+1;
    }
};