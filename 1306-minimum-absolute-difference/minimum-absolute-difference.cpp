class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini = INT_MAX;
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i = 1;i<n;i++){
            int fir = arr[i-1], sec = arr[i];
            if(mini>abs(fir-sec)){
                mini = abs(fir - sec);
                ans.clear();
                ans.push_back({fir,sec});
            }
            else if(mini == abs(fir-sec))
                ans.push_back({fir,sec});
        }
        return ans;
    }
};