#include <iostream>
#include <algorithm>

using namespace std;

class Point{
    public:
        int num, x, y;
    Point(){};
    Point(int num, int x, int y){
        this->num = num;
        this->x = x;
        this->y = y;
    }
};

bool cmp(Point a, Point b){
    int a_dist = abs(a.x-0)+abs(a.y-0);
    int b_dist = abs(b.x-0)+abs(b.y-0);
    if (a_dist ==b_dist) return a.num < b.num; 
    return a_dist < b_dist;
}
int main() {
    int n;
    cin >> n;
    Point points[n];
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        points[i] = Point(i+1, x, y);
    }
    sort(points, points+n, cmp);
    for(int i=0; i<n; i++){
        cout << points[i].num << '\n';
    }
    return 0;
}