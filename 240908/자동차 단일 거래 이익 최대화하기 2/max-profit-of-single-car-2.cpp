#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int n;
vector<pair<int,int> > price; // <현재가격,최소가격>

int main() {
    cin >> n;
    price.resize(n);

    int min_val=2e9;
    for(int i=0; i<n; ++i){
        cin >> price[i].first;
        min_val = min(min_val, price[i].first);
        price[i].second=min_val;
    }

    sort(price.begin(), price.end());
/*
2 2
3 2
6 2
9 9
10 9
*/
    int answer=0;
    for(int i=0; i<n; ++i){
        int gain=price[i].first-price[i].second;
        answer = max(answer, gain);
    }
    cout << answer << '\n';
    return 0;
}