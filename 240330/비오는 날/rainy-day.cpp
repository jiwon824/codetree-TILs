#include <iostream>
#include <algorithm>
using namespace std;
class Data{
    public:
        string date, dayOfWeek, weather;
    Data(string date="", string dayOfWeek="",  string weather=""){
        this->date = date;
        this->dayOfWeek = dayOfWeek;
        this->weather = weather;
    }
    bool operator<(Data d){
        return this->date < d.date;
    }
};
int main() {
    int n;
    cin >> n;
    Data d[100];
    
    for (int i=0;i<n;i++){
        string date, dayOfWeek, weather;
        cin >> date >> dayOfWeek >> weather;
        d[i] = Data(date, dayOfWeek, weather);
    }
    sort(d, d+n);

    for (int i=0;i<n;i++){
        if(d[i].weather == "Rain"){
            cout << d[i].date << " " << d[i].dayOfWeek << " " << d[i].weather;
            break;
        }
    } 
    return 0;
}