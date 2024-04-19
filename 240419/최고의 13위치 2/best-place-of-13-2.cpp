#include <iostream>

using namespace std;
int arr[21][21];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int answer =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            for(int k=i+1; k<n; k++){
                for(int l=0; l<n-2; l++){
                    int sum_ij = arr[i][j]+arr[i][j+1]+arr[i][j+2];
                    int sum_kl = arr[k][l]+arr[k][l+1]+arr[k][l+2];
                    answer=max(answer, sum_ij+sum_kl);
                }
            }
        }
    }
    cout << answer;
    return 0;
}