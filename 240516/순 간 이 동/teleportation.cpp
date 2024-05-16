#include <iostream>

using namespace std;


int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    // a에서 출발
    int min_dist =200; //0 100 100 0일 경우 200 이동하게 됨
    // 방법1. a b
    int dist = abs(a-b);
    if(dist<min_dist) min_dist = dist;
    // 방법2. (a x) (y b)
    dist = abs(a-x)+abs(y-b);
    if(dist<min_dist) min_dist = dist;

    // 방법3. (a y) (x b)
    dist = abs(a-y)+abs(x-b);
    if(dist<min_dist) min_dist = dist;

    cout << min_dist<<'\n';
    return 0;
}