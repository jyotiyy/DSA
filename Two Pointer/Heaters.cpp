link: https://leetcode.com/problems/heaters/description/?envType=problem-list-v2&envId=two-pointers

Verygood solution you first minimize using right side heaters then left side 
We also have a binary search solution for this which will find the mid always between the 
range 0 to 1e9 ;)

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int n = houses.size();
        vector<int> dist(n,INT_MAX);
        //selecting only right side heaters
        for(int i = 0,h = 0; i < n && h < heaters.size(); ){
            if(houses[i] <= heaters[h]){
                dist[i] = heaters[h]-houses[i];
                i++;
            }else{ h++; }
        }
        //selecting only left side heaters
        for(int i = n-1, h = heaters.size()-1; i >= 0 && h >= 0;){
            if(houses[i] >= heaters[h]){
                dist[i] = min(dist[i],houses[i]-heaters[h]);
                i--;
            }else{ h--; }
        }
        return *max_element(dist.begin(),dist.end());



    }
};

class Solution {
public:
    int f(vector<int> &houses,vector<int> &heaters,int m,int n1,int n2){
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(abs(houses[i] - heaters[j]) <= m)i++;
            else
            j++;
            if(j == n2) return false;
        }
        return i == n1;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int n = houses.size();
        int m = heaters.size();
        int ans = -1;
        int l = 0, r = 1e9;
        int mid;
        while(l <= r){
            mid = l+(r-l)/2;
            if(f(houses,heaters,mid,n,m)){
                r = mid-1;
                ans = mid;

            }else l = mid+1;

        }
        return ans;



    }
};