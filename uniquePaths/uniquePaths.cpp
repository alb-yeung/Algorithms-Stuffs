class Solution {
public:
    /* runs in 0ms on leetcode */
    int uniquePaths(int m, int n) {
        int paths[n][m];
        for (int i = 0; i < m; i++){
            paths[0][i] = 1;
        }
        for (int i = 0; i < n; i++){
            paths[i][0] = 1;
        }
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[n-1][m-1];
    }
};
