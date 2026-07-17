class Solution {
public:
    int helperInc(vector<int>& rating, int i, int cnt, int prevIndex,
                  vector<vector<vector<int>>>& dp) {
        if (cnt == 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][cnt][prevIndex] != -1)
            return dp[i][cnt][prevIndex];
        int notTake = helperInc(rating, i - 1, cnt, prevIndex, dp);
        int take = 0;
        if (prevIndex == (int)rating.size() ||
            rating[i] < rating[prevIndex]) {
            take = helperInc(rating, i - 1, cnt - 1, i, dp);
        }
        return dp[i][cnt][prevIndex] = take + notTake;
    }

    int helperDec(vector<int>& rating, int i, int cnt, int prevIndex,
                  vector<vector<vector<int>>>& dp) {
        if (cnt == 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][cnt][prevIndex] != -1)
            return dp[i][cnt][prevIndex];
        int notTake = helperDec(rating, i - 1, cnt, prevIndex, dp);
        int take = 0;
        if (prevIndex == (int)rating.size() ||
            rating[i] > rating[prevIndex]) {
            take = helperDec(rating, i - 1, cnt - 1, i, dp);
        }
        return dp[i][cnt][prevIndex] = take + notTake;
    }

    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<vector<int>>> dpInc(n, vector<vector<int>>(4, vector<int>(n + 1, -1)));
        vector<vector<vector<int>>> dpDec(n, vector<vector<int>>(4, vector<int>(n + 1, -1)));
        int increasing = helperInc(rating, n - 1, 3, n, dpInc);
        int decreasing = helperDec(rating, n - 1, 3, n, dpDec);
        return increasing + decreasing;
    }
};