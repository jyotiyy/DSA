//flattening doesnt work here as rows are internally sorted but not inter rows 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        //starting from bottom-left or you colud do top-right also
        int row = r-1;
        int col = 0;
        while(row >= 0 && col < c){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target){
                row--;
            }else{
                col++;
            }

        }
        return false;
    }
};