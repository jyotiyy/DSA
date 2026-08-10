link: https://leetcode.com/problems/stone-game-iv/

The problem Stone-IV is a gameefied version . Where the problem asks if Alice could win the game 
of stones . Now here solve(n) or t[n] -> represents can they win with this value of n the current player 
.Also the time complexity is O(n*root(n));


/*Memoization */
class Solution {
public:
    vector<int> t;
    bool solve(int n){
        if(n == 0) return false;
        if(t[n] != -1) return t[n] == 1;

        for(int k = 1; k*k <= n; k++){ //if alice at k
            if(solve(n-k*k) == false){ // if bob lose for n-k*k
                return t[n] = true;
            }
        }

        return false;
    }
    bool winnerSquareGame(int n) {
        t.resize(n+1,-1);
        return solve(n);
    }
};

/* Bottom - Up   tabulation */
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        for(int i = 0; i <= n; i++){
            for(int k = 1; k*k <= i; k++){
                if(dp[i-k*k] == false){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};