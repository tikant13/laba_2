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

bool check(const map <char, int>& Str){ //тут мы проверяем на то является ли это палиндромом
    int  prov = 0; // для проверки
    for (auto i : Str){ 
        if (i.second % 2 == 1){
            prov +=1;
            if (prov >1){
                return 0;
            }
        }
    }
    return 1;
}

string polindrom(const map<char, int>& Str){ // полиндром строим 
    string left = "";
    string middle = "";

    for (auto i : Str){ // строим левую часть и середину
        left += string(i.second / 2, i.first);
        if (i.second % 2 == 1){
            middle = string(1, i.first);
        }
    }

    string right = left; // правая часть — зеркальная
    reverse(right.begin(), right.end());

    return  (left + middle + right);
}

int main(){
    string oldStr;
    map <char, int> Str; // тут мы будем хранить кол-во букв
    cin >> oldStr; //вводим строку
    Str = sumChar(oldStr);

    
    bool check_polin = check(Str); //тут мы проверяем на то является ли это палиндромом

    if (check_polin == 0){
        cout << "No" << endl;
        return 0;
    } else {
        cout << "Yes" <<endl;
    }

    cout << polindrom(Str) << endl; // выводим полиндром
    return 0;
}