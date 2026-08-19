link: https://leetcode.com/problems/cinema-seat-allocation/?envType=daily-question&envId=2026-08-19


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int,char> seats;
        for(auto &s: reservedSeats){
           if(s[1] > 1 && s[1] < 10){
             seats[s[0]] |= 1 << (s[1]-2);
           }
        }
       long long ans = 2LL * (n - seats.size()); 
        for(auto [row,seat]:seats){
            bool left = (seat & 0b11110000) == 0;
            bool mid = (seat & 0b00111100) == 0;
            bool right = (seat & 0b00001111) == 0;
            if(left && right) ans += 2;
            else if(left || right || mid) ans++;
            
        }
        return ans;
    }
};

//***********   Failed because of n  = 10^9 T_T **************//

// vector<vector<int>> seats(n + 1, vector<int>(11, 0));
//         for(auto &s: reservedSeats){
//             seats[s[0]][s[1]] = 1;
//         }
//         int count = 0;
//         for(int j = 1; j <= n; j++){
//             bool left = !seats[j][2] && !seats[j][3] && !seats[j][4] && !seats[j][5];
//             bool middle = !seats[j][4] && !seats[j][5] && !seats[j][6] && !seats[j][7];
//             bool right = !seats[j][6] && !seats[j][7] && !seats[j][8] && !seats[j][9];
//             if(left && right) count+=2;
//             else if(left || right || middle) count++;
//         }
//         return count;