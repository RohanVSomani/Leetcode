class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {

        sort(occupiedIntervals.begin(), occupiedIntervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        int ind = 0;
        for (int i = 1; i < occupiedIntervals.size(); ++i) {
            if (occupiedIntervals[i][0] <= occupiedIntervals[ind][1] + 1) {
                occupiedIntervals[ind][1] =
                    max(occupiedIntervals[ind][1], occupiedIntervals[i][1]);

            } else {
                ind++;
                occupiedIntervals[ind] = occupiedIntervals[i];
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i <= ind; i++) {
            if (occupiedIntervals[i][1] < freeStart) {
                ans.push_back(occupiedIntervals[i]);
            }
            if (occupiedIntervals[i][0] < freeStart &&
                occupiedIntervals[i][1] >= freeStart) {
                ans.push_back({occupiedIntervals[i][0], freeStart - 1});
            }
            if (occupiedIntervals[i][0] <= freeEnd &&
                occupiedIntervals[i][1] > freeEnd) {
                ans.push_back({freeEnd + 1, occupiedIntervals[i][1]});
            }
            if (occupiedIntervals[i][0] > freeEnd) {
                ans.push_back(occupiedIntervals[i]);
            }
        }
        return ans;
    }
};