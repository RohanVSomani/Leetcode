class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rows = k;
        int cols = k;
        vector<vector<int>>chosen(rows,vector<int>(cols,0));
        for(int i=x;i<x+k;i++){
            vector<int> row;
            for(int j=y;j<y+k;j++)
            row.push_back(grid[i][j]);
            chosen.push_back(row);
        }
        reverse(chosen.begin(),chosen.end());
        int a=0;
        for(int i=x;i<x+k;i++,a++){
            int b=0;
            for(int j=y;j<y+k;j++,b++)
            grid[i][j] = chosen[a][b];
        }
        return grid;

    }
};