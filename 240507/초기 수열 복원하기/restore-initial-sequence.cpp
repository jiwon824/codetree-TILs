#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
1이상 n이하의 숫자들이 한 번씩만 등장
초기 수열이 {3, 1, 5, 2, 4}일 경우 
주어지는 수열은 인접한 원소들의 합으로 구성된 수열 {4, 6, 7, 6}
초기 수열을 주어진 수열로 바꾸는 건 쉽다.
{arr[0]+arr[1], arr[1]+arr[2], arr[2]+arr[3], arr[3]+arr[4]}

토론에서 본 설명을 바탕으로 재구성
input[] = {4, 6, 7, 6}이 주어지면
arr[0]이 1이라고 가정
arr[1]은 input[0]-arr[0]; //4-1=3
arr[2]는 input[1]-arr[1]; // 6-3 =3 ->중복된 수니까 arr[0] !=1

arr[0]이 2라고 가정
arr[1]은 input[0]-arr[0]; //4-2=2 ->중복 arr[0]!=2

arr[0]이 3이라고 가정
arr[1]은 input[0]-arr[0]; // 4-3=1
arr[2]는 input[1]-arr[1]; //6-1=5
arr[3]은 input[2]-arr[2]; //7-5=2
arr[4]은 input[3]-arr[3]; //6-2=4
=>정답
*/

vector<int> input_v;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int num;
        cin >> num;
        input_v.push_back(num);
    }

    for(int i=1; i<=n;i++){
        vector<int> init_v; // 초기수열
        init_v.push_back(i); // 초기 수열의 첫 원소가 i라고 가정
        for(int j=1; j<n; j++){
            int num = input_v[j-1]-init_v[j-1];
            // num의 범위는 1이상 n이하
            if(num <= 0) break;
            if(find(init_v.begin(), init_v.end(), num) != init_v.end()) break;
            
            // num이 중복 원소가 아니라면 초기 수열 init_v에 추가
            init_v.push_back(num);
        }

        if(init_v.size()==n){
            for(auto e : init_v){
                cout << e << " ";
            }
            break;
        }
    }

    return 0;
}