#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


    // 숫자들의 합(n개의 수 중 2개를 제외하고 더한 값)-s 의 절대값을 구하면,
    // 그 중 가장 작은 값(절대값이 0에 가장 가까운 수)이 정답
    int answer=10001; // 100이 100개 주어지니까 
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum =0;
            for(int k =0; k<n; k++){
                //i번째, j번째 인덱스를 제외한 숫자들의 합을 구한다.
                if(k==i || k==j) continue;
                sum += arr[k];
            }
            if(answer>abs(sum-s)) answer=abs(sum-s);
        }
    }
    
    cout << answer;

    return 0;
}