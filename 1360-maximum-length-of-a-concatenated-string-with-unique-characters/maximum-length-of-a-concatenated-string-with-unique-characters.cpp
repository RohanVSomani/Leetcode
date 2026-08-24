class Solution {
public:
    void helper(vector<string>& arr,int i, string curr,string &ans){
        if(i<0){
            if(ans.size()<curr.size())
                ans = curr;
            return;
        }
        string take = curr+arr[i];
        set<char> freq;
        for(char c:take){
            freq.insert(c);
        }
        if(take.size() == freq.size())
            helper(arr,i-1,take,ans);
        helper(arr,i-1,curr,ans);

    }
    int maxLength(vector<string>& arr) {
        string ans = "";
        helper(arr,arr.size()-1,"",ans);
        return ans.size();
    }
};