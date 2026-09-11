//A[i][j] = largest submatrix with all ones with bottom right number (i,j) which has value 1 


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        if(r == 0) return 0;
        int res = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0;j<c; j++){
                if(matrix[i][j] == 1 && i > 0 && j > 0){
                    matrix[i][j] = 1+min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});
                }
                res+=matrix[i][j];
            }
        }
        return res;

    }
};