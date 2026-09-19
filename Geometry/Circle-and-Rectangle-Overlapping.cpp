class Solution {
public:
    //wkt perpendicular segments are the shortest paths from a point to a line 
    //if this minimum length is at most the circle radius they overlap
    //so here we compute the shortest distanc between the center of the circle and the boundary of rectangle
    //so now we are considering to find the xmin and ymin xmin belongs to [x1,x2] and ymin belongs to [y1,y2]
    //then the point (xc+xmin,yc+ymin) is the nearest point
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long dist = 0;
        if(xCenter < x1 || xCenter > x2){
            dist += min(pow(x1-xCenter,2),pow(x2-xCenter,2));
        }
        if(yCenter < y1 || yCenter > y2){
            dist += min(pow(y1-yCenter,2),pow(y2-yCenter,2));
        }
        return dist <= radius*radius;
    }
};