#include <iostream>
#include <algorithm>

vector<int> v;

bool IsAnswer(int a, int b, int c, int d){
    vector<int> tmp;

}
int main() {
    // A, B, C, D
    // (A + B), (B + C), (C + D), (D + A), (A + C), (B + D)
    // (A + B + C), (A + B + D), (A + C + D), (B + C + D)
    // (A + B + C + D)
    int n = 15;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    // A ≤ B ≤ C ≤ D 조건을 만족하는 4개의 정수 A, B, C, D라고 했고,
    // 정렬했기 때문에 맨 앞의 4개의 원소는 a, b, c, d일 수밖에 없음
    cout << v[0] << " "<< v[1]<< " " << v[2] << " " <<v[3]<<'\n'
    // j=i+1, k=j+1, l=k+1이 될 수 있음(정렬해서 무조건 v[i]<=v[j]<=v[k]<=v[l])
    //for(int i=0; i<n; i++){
    //    for(int j=i+1; j<n; j++){
    //        for(int k=j+1; k<n; k++){
    //            for(int l=k+1; l<n; l++){
    //                int a=v[i], b=v[j], c=v[k], d=v[l];
    //                
    //            }
    //        }
    //    }
    //}
    return 0;
}