#include <iostream>

using namespace std;

int *arr;
int n;

int GCD(int n, int m){
    if(n*m==0) return n+m;
    return GCD(m, n%m);
}

int LCM(int a, int b){
    return a*b/GCD(a, b);
}

// n 개의 수 a[0], ... , a[n-1]이 주어졌을 때, 이 수들의 합을 구하는 코드
//int Sum (int idx){
//    if(idx==0) return arr[idx];
//    return Sum(idx-1)+arr[idx];
//}

// n개의 수가 주어졌을 때 최소공배수 구하기
int LCMAll(int idx){
    if(idx==0) return arr[idx];
    return LCM(LCMAll(idx-1), arr[idx]);
}
int main() {
    //input
    cin >>n;
    arr = new int[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    //lcm[0]=arr[0];
    //lcm[1]=arr[1];
    //for(int i=2;i<n;i++){
    //    int a = lcm[i-1];
    //    int b = arr[i];
    //    lcm[i]=a*b/GCD(a, b);
    //    //cout << "i: "<< i << " "<< lcm[i] <<'\n';
    //}
    cout << LCMAll(n-1);
    return 0;
}