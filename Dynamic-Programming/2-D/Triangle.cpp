link: https://leetcode.com/problems/triangle/description/
The problem statement mentions about the movement in a triangle as , from current row at index i 
either i or i+1 of next row. This clarifies [i-1][j-1] or [i-1][j] 
but ignoring the triangle[0][0] iteration also for every n-1th element of a row we cannot have its 
[i-1][j] 
2
3 6 
6 5 7 
4 1 8 3
Think of it in this manner .;)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for(int i = 1; i < m; i++){
            int n = triangle[i].size();
            triangle[i][0] += triangle[i-1][0];

            for(int j = 1; j < n-1; j++){
                triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
            }
            triangle[i][n-1] += triangle[i-1][n-2];
        }
        int n = triangle[m-1].size();
        int val = INT_MAX;
        for(int i = 0; i < n; i++){
            val = min(val,triangle[m-1][i]);
        }
        return val;
    }
};