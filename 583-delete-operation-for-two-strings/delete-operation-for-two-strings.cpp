class Solution {
public:
    int helper(string word1, string word2, int i, int j,vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j] = 1 + helper(word1,word2,i-1,j-1,dp);
        else
            return dp[i][j] = max(helper(word1,word2,i,j-1,dp),helper(word1,word2,i-1,j,dp));
    }
    int minDistance(string word1, string word2) {
        int w1 = word1.size(), w2 = word2.size();
        vector<vector<int>> dp(w1+1,vector<int>(w2+1,-1));
        int ans = helper(word1,word2,w1-1,w2-1,dp);
        int del = abs(w1 - ans);
        int add = abs(w2 - ans);
        return del+add;
    }
};