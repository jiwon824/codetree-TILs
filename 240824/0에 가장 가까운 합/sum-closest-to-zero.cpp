#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int n;
int num[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    sort(num, num+n);

    // answer=min(answer, abs(a+b))
    int r=n-1, answer=2e9;
    for(int l=0; l<n; ++l){
        if(l<r) answer = min(answer, abs(num[l]+num[r]));

        // a[i]+a[j]>0은 a[j]가 엄청 크다는 의미 a[i]=-1인데 a[j]=1000000 같은 경우
        while(r-1>l && num[l]+num[r]>0){
            r--;
            answer = min(answer, abs(num[l]+num[r]));
        }
        if(r < l) break;
    }
    cout << answer << '\n';
    return 0;
}