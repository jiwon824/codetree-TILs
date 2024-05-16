#include <iostream>

using namespace std;

int main() {
    int n;
    string seats;
    cin >> n >> seats;

    int answer=0;
    // seats[i]자리를 1로 채웠을 때
    for(int i=0; i<n; i++){
        if(seats[i]=='1') continue;

        seats[i]='1';
        int min_dist =1000;
        //cout << seats <<'\n';
        for(int left=0; left<n-1; left++){
            if(seats[left]=='0') continue;
            //cout << left <<" ";
            int dist =0;
            for(int right=left+1; right<n; right++){
                if(right==n-1 && seats[right]=='0') dist=1000;
                if(seats[right]=='1'){
                    dist = right-left;
                    //cout << left << " " << right << " "<< dist << '\n';
                    break;
                }
            }
            if(dist<min_dist) min_dist = dist;
            //cout << "min_dist: "<< min_dist<<'\n';
        }
        //cout << min_dist <<'\n';

        if(answer<min_dist) answer = min_dist;
        seats[i]='0';
    }
    cout << answer <<'\n';
    return 0;
}