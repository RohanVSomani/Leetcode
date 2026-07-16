class Solution {
public:
    long long gcdCalc(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i =0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            long long curr = gcdCalc(nums[i],maxi);
            ans.push_back(curr);
            cout<<curr<<"\t";
        }
        sort(ans.begin(),ans.end());
        long long res = 0;
        int l =0,r=ans.size()-1;
        while(l<=r){
            if(l==r)
                break;
            int gcdCurr = gcdCalc(ans[r],ans[l]);
            l++;
            r--;
            res+=gcdCurr;
        }
        return res;
    }
};