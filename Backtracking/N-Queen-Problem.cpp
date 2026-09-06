// Given an integer n, place n queens on an n × n
// chessboard such that no two queens attack each 
// other.

#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> res;
int n;
bool isSafe(vector<string> &board,int r,int c){
    //checking that column;
    for(int i = 0; i < r; i++){
        if(board[i][c] == 'Q') return false;
    }
    //checking upper left diagonal
    for(int i = 1; i <= min(r,c); i++){
        if(board[r-i][c-i] == 'Q')return false;
    }
    //checking upper right diagonal
    for(int i = 1; i <= min(r,n-c-1); i++){
        if(board[r-i][c+i] == 'Q') return false;
    }
    return true;
}
void backtrack(vector<string> &board,int r){
    if(r == board.size()){
        res.push_back(board);
        return;
    }
    for(int col = 0; col < board.size(); col++){
        if(isSafe(board,r,col)){
            board[r][col] = 'Q';
            backtrack(board,r+1);
            board[r][col] = '.';
        }
    }
}
int main(){
    cin>> n;
    vector<string> board(n,string(n,'.'));
    backtrack(board,0);
    for(vector<string> &result:res){
        for(string s: result){
            cout << s << " ";
        }
        cout << "\n";
    }
}