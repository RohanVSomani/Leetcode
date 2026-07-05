class Solution {
public:
    int helper(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = 1+helper(s,t,i-1,j-1,dp);
        else
            return dp[i][j] = max(helper(s,t,i,j-1,dp),helper(s,t,i-1,j,dp));
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        
        reverse(t.begin(),t.end());
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans = helper(s,t,n-1,n-1,dp);
        return ans;
    }
};