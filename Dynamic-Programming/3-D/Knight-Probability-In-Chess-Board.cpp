class Solution {
public:
    //tc O(k*n^2)
    // dp[move][i][j] = probability that knight is at i,j after move moves
    //at 0th move knight probability is 1 at the position it starts

    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int,int>> direc = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        vector<vector<vector<double>>> dp(k+1,
                                       vector<vector<double>>(n,vector<double>(n,0)));
        dp[0][row][column] = 1;
        for(int mov = 1; mov <= k; mov++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(const auto&dir: direc){
                        int pi = i-dir.first;
                        int pj = j-dir.second;

                        if(pi >= 0 && pi < n && pj >= 0 && pj < n){
                            dp[mov][i][j] += dp[mov-1][pi][pj]/8.0; //all possible positions from where it could have came to i,j

                        }
                    }
                }
            }
        }

        double totalProb = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                totalProb += dp[k][i][j];
            }
        }
        return totalProb;

    }
};