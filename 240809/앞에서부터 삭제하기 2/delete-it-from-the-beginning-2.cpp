#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec_numbers(n+1);
    
    for(int i=0; i<n; ++i){
        cin >> vec_numbers[i];
    }

    priority_queue<float> avg;
    for(int i=0; i<n-2; ++i){
        priority_queue<int> pq_numbers;
        // 앞에서부터 K개(1<=K<=N-2)를 삭제하고 난 후,
        int delNum=vec_numbers[i];
        int sum =0;
        for(int j=i+1; j<n; ++j){
            // 남아있는 정수 중 "가장 작은 숫자" 하나를 제외한 평균을 구해야 하므로 -를 붙여서 push
            // 0 ≤ 주어지는 정수 ≤ 10,000이라 가능
            pq_numbers.push(-vec_numbers[j]);
            sum+=vec_numbers[j];
        }
        
        int minValue = -pq_numbers.top();
        sum-= minValue;
        avg.push((float)sum / (pq_numbers.size()-1));
    }

    // 남아있는 수들의 평균값이 최대를 소수점 두 자리수까지 출력
    cout<<fixed;
    cout.precision(2);
    cout << avg.top() << '\n';
    return 0;
}