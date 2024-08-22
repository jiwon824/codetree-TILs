#include <iostream>
using namespace std;

const int MAX_N = 1000001;

int n;
int arr[MAX_N];
int count_array[MAX_N];

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    // solution
    int r=0, answer=0;
    for(int l=0; l<n; ++l){
        while(r<n && count_array[arr[r]]==0){
            count_array[arr[r]]=1;
            r++;
        }

        answer = max(answer, r-l);
        count_array[arr[l]]=0;
    }
    
    // output
    cout << answer << '\n';
    return 0;
}