link: https://leetcode.com/problems/unique-paths-ii/description/

This problem is different from part 1 only by including set of block and pass constraints 
.That is 1 in a cell means the path is blocked from that way and 0 means free 
to minimize this further i changed the 1 in the cells to -1 so that i can differentiate the count 1 and 
blockage 1 . Now we first take care about the base cases like if the first cell is blocked there are 0 paths 
and then same as unique path problem grid[i][j] = 1+ grid[i-1][j]+grid[i][j-1] 
but ignoring the cells with -1 this time .

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        if(m == 1 && n == 1){
            if(obstacleGrid[0][0] == 1) return 0;
            return 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        obstacleGrid[0][0] = 1;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == -1) continue;
                if(i-1 >= 0 && obstacleGrid[i-1][j] != -1){
                    obstacleGrid[i][j] += obstacleGrid[i-1][j];
                }
                if(j-1 >= 0 && obstacleGrid[i][j-1] != -1){
                    obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
            }
        }
        if(obstacleGrid[m-1][n-1] == -1) return 0;
        
        return obstacleGrid[m-1][n-1];
    }
};
