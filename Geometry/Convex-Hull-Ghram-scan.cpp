
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x)
            - (b.x - a.x) * (c.y - b.y);

    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise : Counterclockwise
}

int distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x)
         + (a.y - b.y) * (a.y - b.y);
}

bool compare(Point a, Point b) {
    int o = orientation(p0, a, b);

    if (o == 0)
        return distSq(p0, a) < distSq(p0, b);

    return o == 2;
}

vector<Point> convexHull(vector<Point> points) {
    int n = points.size();

    if (n < 3) return {};

    // Find the lowest point
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[pos].y ||
           (points[i].y == points[pos].y &&
            points[i].x < points[pos].x))
            pos = i;
    }

    swap(points[0], points[pos]);
    p0 = points[0];

    // Sort points by polar angle
    sort(points.begin() + 1, points.end(), compare);

    vector<Point> st;

    for (auto p : points) {
        while (st.size() >= 2 &&
               orientation(st[st.size()-2], st.back(), p) != 2) {
            st.pop_back();
        }
        st.push_back(p);
    }

    if (st.size() < 3) return {};
    return st;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull Points:\n";
    for (auto p : hull)
        cout << p.x << " " << p.y << "\n";

    cout << "Number of vertices: " << hull.size() << "\n";

    return 0;
}
