class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> pSum(m,vector<int>(n,0));
        int cnt = 0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(i==0 && j==0){
                    pSum[i][j] = grid[i][j];
                }
                else if(j==0){
                    pSum[i][j]=pSum[i-1][j] + grid[i][j];
                }
                else if(i==0){
                    pSum[i][j]=pSum[i][j-1] + grid[i][j];
                }
                else{
                    pSum[i][j] = pSum[i-1][j] + pSum[i][j-1]+grid[i][j]-pSum[i-1][j-1];

                }
                if(pSum[i][j] <= k){
                cnt++;
                }
            }
        }
        return cnt;
    }
};