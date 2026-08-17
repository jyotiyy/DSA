link: https://leetcode.com/problems/unique-paths/description/
This problem specifies that it requires us to find all possible unique paths from (0,0) to 
(m-1,n-1) .Thus we assume 1 for grid[0][0] as that's the start 
then for every (i,j) all possibilites to that position are from either (i-1,j) or (i,j-1)
thus grid[i][j] = 1+grid[i-1][j]+grid[i][j-1]

class Solution {
public:
    int uniquePaths(int m, int n) {
        int grid[m][n];
        memset(grid,0,sizeof(grid));
        grid[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i-1 >= 0){
                    grid[i][j] += grid[i-1][j];
                }
                if(j-1 >= 0){
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
