#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 50001;

int n;
int card[2*MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        card[num]=1; // b가 가지고 있는 카드
    }

    vector<int> a;
    vector<int> b;
    for(int i=1; i<=2*n; ++i){
        if(card[i]==1) b.push_back(i);
        else a.push_back(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int a_pointer=0, answer=0;
    for(int i=0; i<n; ++i){
        while (a_pointer+1<n && b[i]>a[a_pointer]){
            a_pointer++;
        }
        
        if(a[a_pointer]>b[i]) answer++;
    }
    cout << answer << '\n';
    return 0;
}