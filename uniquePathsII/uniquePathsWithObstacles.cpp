class Solution {
public:
    /* runs in 4ms on leetcode will try to optimize */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int paths[n][m];
        for (auto & i : paths){
            for (int & j : i){
                j = 0;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (obstacleGrid[i][j] == 1){
                    continue;
                }
                if (i == 0 && j == 0){
                    paths[i][j] = 1;
                    continue;
                }
                if (i > 0 && j > 0) paths[i][j] = paths[i-1][j] + paths[i][j-1];
                else if (i > 0) paths[i][j] = paths[i-1][j];
                else paths[i][j] = paths[i][j-1];
            }
        }
        return paths[n-1][m-1];
    }
};
