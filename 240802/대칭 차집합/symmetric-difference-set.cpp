#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int numA, numB;
unordered_set<int> a;
vector<int> aVec;
unordered_set<int> b;
vector<int> bVec;


int main() {
    // input
    cin >> numA >> numB;
    for(int i=0; i<numA; ++i){
        int e;
        cin >> e;
        a.insert(e);
        aVec.push_back(e);
    }
    for(int i=0; i<numB; ++i){
        int e;
        cin >> e;
        b.insert(e);
        bVec.push_back(e);
    }

    // solution
    int aDiffb=0, bDiffa=0;
    for(int i=0; i<numA; ++i){
        if(b.find(aVec[i])==b.end()) aDiffb++;
    }
    for(int i=0; i<numB; ++i){
        if(a.find(bVec[i])==a.end()) bDiffa++;
    }
    
    // output
    cout << aDiffb+bDiffa << '\n';

    return 0;
}