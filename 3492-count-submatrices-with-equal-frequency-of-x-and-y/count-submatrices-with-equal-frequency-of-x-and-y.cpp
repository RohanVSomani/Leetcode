class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> helper(m,vector<pair<int,int>>(n,{0,0}));
        for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

        int xcount = 0;
        int ycount = 0;

        if(i > 0) {
            xcount += helper[i-1][j].first;
            ycount += helper[i-1][j].second;
        }

        if(j > 0) {
            xcount += helper[i][j-1].first;
            ycount += helper[i][j-1].second;
        }

        if(i > 0 && j > 0) {
            xcount -= helper[i-1][j-1].first;
            ycount -= helper[i-1][j-1].second;
        }

        if(grid[i][j] == 'X') xcount++;
        else if(grid[i][j] == 'Y') ycount++;

        helper[i][j] = {xcount, ycount};
        }
}
        int cnt = 0;
        for(auto row:helper){
            for(auto it:row){
                int xcount = it.first;
                int ycount = it.second;
                if(xcount == ycount && xcount>0)
                cnt++;
            }
        }
        return cnt;
    }
};