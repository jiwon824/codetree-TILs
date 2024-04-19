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
            for(int k=0; k<n; k++){
                for(int l=0; l<n-2; l++){
                    if(i==k &&((j==l || j+1==l || j+2==l) || (l==j || l+1==j || l+2==j))) continue;
                    int sum_ij = arr[i][j]+arr[i][j+1]+arr[i][j+2];
                    int sum_kl = arr[k][l]+arr[k][l+1]+arr[k][l+2];
                    //cout << "ij "<< i << "/ "<< j << " " << j+1 << " "<< j+2 << '\n';
                    //cout << "kl "<< k << "/ "<< l << " " << l+1 << " "<< l+2 << '\n';
                    answer=max(answer, sum_ij+sum_kl);
                }
            }
        }
    }
    cout << answer;
    return 0;
}