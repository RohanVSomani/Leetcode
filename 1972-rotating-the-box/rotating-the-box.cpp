class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        for(auto& row:boxGrid){
            int j = n-1;
            int i = n-1;
            while(i>=0){
            if(row[i]=='#' && row[j]=='.'){
                row[j]=row[i];
                row[i]='.';
                j--;
            }
            if(row[j]!='.')
            j--;
            if(row[i]=='*'){
                j=i-1;
            }
            i--;
            }
        }
        vector<vector<char>> trans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            trans[j][i] = boxGrid[i][j];
            }
        }
        for(auto& row:trans){
            reverse(row.begin(),row.end());
        }
        return trans;
    }
};