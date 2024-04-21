#include <iostream>
#include <climits>
using namespace std;
int arr[6];
int main() {
    int sum =0;
    for(int i=0; i<6; i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    int min_diff =INT_MAX;
    for(int i=0; i<3; i++){
        int team_a =0;
        for(int j=i; j<=i+3;j++){
            team_a+=arr[j];
        }
        int team_b = sum - team_a;
        int diff = abs(team_a-team_b);
        if(diff<min_diff)min_diff = diff;
    }
    cout << min_diff;
    return 0;
}