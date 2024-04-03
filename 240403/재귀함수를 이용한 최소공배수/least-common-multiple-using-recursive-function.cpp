#include <iostream>

using namespace std;

int *arr;
int *lcm;
int n;

int GCD(int n, int m){
    if(n*m==0) return n+m;
    return GCD(m, n%m);
}

int LCM(int a, int b, int size){
    int lcm = arr[a]*arr[b]/GCD(arr[a], arr[b]);
    if(size<0) return lcm;
    return LCM(a+2, b+2, size-4)*lcm;
}

int main() {
    //input
    cin >>n;
    arr = new int[n];
    lcm = new int[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    lcm[0]=arr[0];
    lcm[1]=arr[1];
    for(int i=2;i<n;i++){
        lcm[i]=lcm[i-1]*arr[i]/GCD(lcm[i-1], arr[i]);
        //cout << "i: "<< i << " "<< lcm[i] <<'\n';
    }
    cout << lcm[n-1];
    return 0;
}