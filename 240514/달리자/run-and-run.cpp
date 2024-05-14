#include <iostream>

using namespace std;

/*
4
5 4 3 1
3 2 3 5

5 4 1 3 // 3번 집 2명 -> 4번 집 (2*1) =2
5 2 1 5 // 2번 집 2명 -> 4번 집 (2*2)=4
3 2 3 5 // 1번 집 2명 -> 3번 집 (2*2)=4

5 4 0 4 // 3번 집 3명 -> 4번 집 (1*3) =3
5 3 0 5 // 2번 집 1명 -> 4번 집(2*1) =2
5 0 3 5 // 2번 집 3명 -> 3번 집(1*3) =3
3 2 3 5 // 1번 집 2명 -> 2번 집(2+1) =2

3 6 3 1 =>2
3 2 7 1 =>4
3 2 3 5 =>4
*/

int a[101];
int b[101];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    int sum_of_dist =0;
    for(int i=0; i<n; i++){
        if(b[i]==a[i]) continue;
        int people = a[i]-b[i];
        //cout << people <<'\n';
        a[i]-=people;
        a[i+1]+=people;
        sum_of_dist +=people;
    }
    cout << sum_of_dist;
    return 0;
}