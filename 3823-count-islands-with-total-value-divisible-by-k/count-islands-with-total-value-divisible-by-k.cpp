class Solution {
public:
    long long bfs(int i,int j, vector<vector<int>> &vis , vector<vector<int>> &grid){
        if(vis[i][j] == 1 || grid[i][j] == 0)
            return 0;
        long long sum = grid[i][j];
        vis[i][j]=1;
        if(j!=0)
            sum += bfs(i,j-1,vis,grid);
        if(i!=0)
            sum += bfs(i-1,j,vis,grid);
        if(j!=grid[0].size()-1)
            sum += bfs(i,j+1,vis,grid);
        if(i!=grid.size()-1)
            sum += bfs(i+1,j,vis,grid);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i =0;i < m;i++){
            for(int j= 0;j < n;j++){
                if(grid[i][j] == 0||vis[i][j]==1)continue;
                else{
                    long long sum = bfs(i,j,vis,grid);
                    if(sum%k == 0)
                     cnt++;
                }
            }
        }
        return cnt;
    }
};