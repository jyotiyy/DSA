link: https://leetcode.com/problems/stone-game/description/

/*Brute force with O(2^n) As we check for all combinations using recursion*/
class Solution {
    public boolean stoneGame(int[] piles) {
        int alice = solve(piles,0,0,true,0,piles.length-1);
        int total = 0;
        for(int x: piles) total+=x;
        return alice > total-alice;
    }
    int solve(int[] piles,int alice,int bob,boolean turn,int l,int r){
        if(l > r) return alice;
        if(turn){
            int left = solve(piles,alice+piles[l],bob,false,l+1,r);
            int right = solve(piles,alice+piles[r],bob,false,l,r-1);
            return Math.max(left,right); //alice tries to maximize her score
        }else{
            int left = solve(piles,alice,bob+piles[l],true,l+1,r);
            int right = solve(piles,alice,bob+piles[r],true,l,r-1);
            return Math.min(left,right); //bob tries to minimize alice score
        }
    }
}

import java.util.Arrays;
/*Memoization here we keep only one place for the alice , that will be like 
 alice-bob > 0 */
class Solution {
    int[][] dp ;
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        dp = new int[n][n];
        for(int[] r: dp){
            Arrays.fill(r,Integer.MIN_VALUE);
        }
        int diff = solve(piles,0,n-1);
        return diff > 0;
        
    }
    int solve(int[] piles,int l,int r){
        if(l == r) return piles[l];
        if(dp[l][r] != Integer.MIN_VALUE) return dp[l][r];
        int left = piles[l]-solve(piles,l+1,r);
        int right = piles[r]-solve(piles,l,r-1);
        return dp[l][r] = Math.max(left,right);
    }
}

import java.util.Arrays;
/* dp[i][j] = Maximum score difference the current player can acheive from piles[i...j]*/

class Solution {
    int[][] dp ;
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        dp = new int[n][n];
        for(int[] r: dp){
            Arrays.fill(r,0);
        }
        for(int len= 2; len <= n; len++){
            for(int l = 0; l +len -1 < n; l++){
                int r = l+len-1;
                dp[l][r] = Math.max(piles[l] - dp[l+1][r],
                               piles[r] - dp[l][r-1]); 
            }
        }
        return dp[0][n-1] > 0;
        
        
    }
    
}