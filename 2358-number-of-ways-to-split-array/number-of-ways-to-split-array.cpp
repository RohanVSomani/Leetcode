class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        vector<long long> pSum(n);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pSum[i]=sum;
        }
        int cnt = 0;
        for(int i =0;i<n-1;i++){
            cout<<pSum[i]<<"\t"<<sum-pSum[i]<<"\n";
            if(pSum[i]>=(sum-pSum[i]))
                cnt++;
        }
        return cnt;
    }
};