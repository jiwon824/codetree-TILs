#include <iostream>
#include <string>

using namespace std;
class Student{
    public:
        string codeName;
        int score;
    Student(string codeName="", int score=0){
        this->codeName = codeName;
        this->score = score;
    }
};
int main() {
    Student student[5];
    for (int i=0;i<5;i++){
        string cName;
        int _score;
        cin >> cName >> _score;
        student[i]= Student(cName, _score);
    }
    string name = "";
    int min = 100;
    for (int i=0;i<5;i++){
        if(student[i].score<min) {
            name = student[i].codeName;
            min = student[i].score;
        }
    }
    cout << name << " " << min;
    return 0;
}