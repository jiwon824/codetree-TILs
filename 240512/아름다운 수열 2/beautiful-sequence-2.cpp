#include <iostream>

using namespace std;

int a[101];
int b_num[101];
int n, m;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        int num;
        cin >>num;
        b_num[num]++;
    }

    int answer =0;
    for(int i=0; i<n-m+1; i++){
        int tmp[101];
        for(int j=0; j<101; j++){
            tmp[j]=b_num[j];
        }
        for(int j=i; j<i+m;j++){
            tmp[a[j]]--;
        }
        
        bool isBeauty = true;
        for(int j=0; j<101; j++){
            if(tmp[j]>0){
                isBeauty = false;
                break;
            }
        }
        if(isBeauty) answer++;
    }

    cout << answer;

    return 0;
}