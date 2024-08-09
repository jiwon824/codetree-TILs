#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec_numbers(n);

    for(int i=0; i<n; ++i){
        cin >> vec_numbers[i];
    }

    float maxAvg =0;
    int sum=0;
    priority_queue<int> pq;
    
    pq.push(-vec_numbers[n-1]);
    sum+=vec_numbers[n-1];

    for(int i=n-2; i>=0; --i){
        pq.push(-vec_numbers[i]);
        sum+=vec_numbers[i];

        int minValue= -pq.top();
        sum-=minValue;
        maxAvg = max (maxAvg, (float)sum/(pq.size()-1));

        sum+=minValue; // minValue를 다시 더해줘야 함
    }

    // 남아있는 수들의 평균값이 최대를 소수점 두 자리수까지 출력
    cout<<fixed;
    cout.precision(2);
    cout << maxAvg << '\n';
    return 0;
}