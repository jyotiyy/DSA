https://codeforces.com/contest/2260/problem/C

The idea is basically maximum possible xor is sum of the 2 numbers x,y 
When we check for the minimum number of operations , so that is possible 
when we set every already set bit from sum and also check if that resultant is 
less than initial x 
int main(){
    ll t;cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int sum = x+y;
        int last = 0;
        for(int i = 63; i >= 0; i--){
            int mask = 1LL << i;
            if((sum&mask)&& last+mask <= x){
                last+=mask;
            }
        }
        cout << sum << " " << x-last << "\n";


    }
}