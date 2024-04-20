#include <iostream>

using namespace std;
int people[101];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int pos;
        char alpha;
        cin >> pos >> alpha;
        if(alpha=='G') people[pos] = 1;
        else people[pos] = 2;
    }

    int answer =0;
    for(int i=0; i<101; i++){
        for(int j=i; j<101; j++){
            int num_of_G=0, num_of_H=0;
            for(int k=i; k<=j; k++){
                if(people[k]==1) {
                    num_of_G++;
                }
                else if(people[k]==2){
                    num_of_H++;
                }
            }
            if(num_of_G==0 && num_of_H==0) continue;
            if(people[i]!=0 && people[j]!=0){
                if(num_of_G==num_of_H || num_of_G==0 || num_of_H==0){
                    //cout << i << " " << j << " " << people[i] << " "<< people[j]<<'\n';
                    int size=j-i;
                    if(answer<size) answer=size;
                }
            }
        }
    }
    cout << answer;
    return 0;
}