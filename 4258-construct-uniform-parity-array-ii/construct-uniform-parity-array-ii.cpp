class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        int mini = INT_MAX;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i]%2!=0)
                odd++;
            mini = min(nums1[i],mini);
        }
        if(odd == 0 || odd == nums1.size())
            return true;
        if(odd!=0){
            if(mini%2!=0)
                return true;
        }
        return false;
    }
};