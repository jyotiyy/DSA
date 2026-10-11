#include<bits/stdc++.h>
using namespace std;
int orient(int x1,int y1,int x2,int y2,int x3,int y3){
    int val = (y2-y1)*(x3-x2) - (y3-y2)*(x2-x1);
    if(val == 0){
        return 0;
    }else if(val > 0) return 1;
    return 2;
}
bool intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    int o1 = orient(x1,y1,x2,y2,x3,y3);
    int o2 = orient(x1,y1,x2,y2,x4,y4);
    int o3 = orient(x3,y3,x4,y4,x1,y1);
    int o4 = orient(x3,y3,x4,y4,x2,y2);
    return (o1 != o2 && o3 != o4);
}
int main(){
    int x1=1, y1=1, x2=4, y2=4;
    int x3=1, y3=4, x4=4, y4=1;
    if(intersect(x1,y1,x2,y2,x3,y3,x4,y4)){
        cout << "Intersect";
    }else{
        cout << "Do not intersect";
    }
}