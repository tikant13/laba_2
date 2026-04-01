#include<iostream> 
#include<algorithm> 
#include<string>
#include<map>
using namespace std;

map <char, int> sumChar(const string& str){ // эта функция отвечает за счёт кол-ва букв 
    map<char, int> result;
    for (char i : str){
        result[i] +=1; 
    }
    return result;
}

int main(){
    string newStr;
    int prov = 0; //проверка
    map <char, int> Str; // тут мы будем хранить кол-во букв
    cin >> newStr; //вводим строку
    Str = sumChar(newStr);

    // for (auto i : Str){
    //     cout << i.first << " " <<i.second << endl;
    // }

    for (auto i : Str){
        if (i.second == 1){
            prov +=1;
            if (prov >1){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}