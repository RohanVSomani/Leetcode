class Solution {
public:
    /*int helper(string s, string t, int i, int j,vector<vector<int>> &dp){
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int matchtake = 0;
        if(s[i] == t[j]){
        matchtake = helper(s,t,i-1,j-1,dp);
        }
        int dont = helper(s,t,i-1,j,dp);
        return dp[i][j] = matchtake+dont;
    }*/
    int numDistinct(string s, string t) {
        int s1 = s.size(), t1 = t.size();
        vector<vector<double>> dp(s.size()+1,vector<double>(t.size()+1,0));
        //int ans = helper(s,t,s.size()-1,t.size()-1,dp);
        for(int i =0;i<=s1;i++)
            dp[i][0] = 1;
        //for(int j=1;j<=t1;j++)
            //dp[0][j] = 0;
        for(int i =1;i<=s1;i++){
            for(int j=1;j<=min(i,t1);j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[s1][t1];
    }
};
