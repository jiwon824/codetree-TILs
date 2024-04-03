#include <iostream>
#include <algorithm>
using namespace std;

class Data{
    public:
        string name;
        int height;
        float weight;
    Data(){};
    Data(string name, int height, float weight){
        this->name = name;
        this->height = height;
        this->weight = weight;
    }
};

bool CmpWithHeight(Data a, Data b){
    return a.height > b.height;
}
bool CmpWithName(Data a, Data b){
    return a.name < b.name;
}
int main() {
    Data d[5];
    for(int i=0;i<5;i++){
        string n;
        int h;
        float w;
        cin >> n >> h >> w;
        d[i] = Data(n, h, w);
    }
    
    cout << fixed;
	cout.precision(1);
    cout <<"name\n";
    sort(d, d+5, CmpWithName);
    for(int i=0;i<5;i++){
        cout << d[i].name << " " <<d[i].height << " " <<d[i].weight<<'\n'; 
    }
    cout <<"\nheight\n";
    sort(d, d+5, CmpWithHeight);
    for(int i=0;i<5;i++){
        cout << d[i].name << " " <<d[i].height << " " <<d[i].weight<<'\n'; 
    }
    return 0;
}