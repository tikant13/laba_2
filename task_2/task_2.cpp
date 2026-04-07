#include<iostream>
#include<string>
#include<set>
using namespace std;

bool limitations (const string& str){ //ПРОВЕРКА

    string symbols = "qwertyuiopasdfghjklzxcvbnm0123456789.+"; // допустимые символы 
    string zapret = "&=+<>,_`-"; // запрещённые символы
    string strName = ""; // имя пользователя
    string strDomen = "@"; // @ + доменное имя

    if (str.find('@') == string::npos){ //если нет @
        return false;
    }

    size_t pos = str.find('@'); 
    strDomen += str.substr(pos + 1); //находим доменное имя

    if (strDomen.find('.') == string::npos || strDomen.size()<4){ //проверяем нормальное ли доменное имя
        return false;
    }

    for (char i : strDomen){ // проверка на запрещённые символы в домене
        bool prov = true;
        for (char j : zapret){
            if (i == j){
                prov = false;
                break;
            }
        }
        if (prov == false){
            return false;
        }
    }
    
    for (char sN : str){ // находим имя пользователя
        if (sN == '@'){
            break;
        }
        else{
            strName+=sN;
        }
    }
    if (strName.size() <6 || strName.size()>30){ // проверка длины имени 
        return false;
    }

    for (int q = 0; q <str.size()-1; q++){ // проверка на несколько точек подряд
        if (str[q] == '.' && str[q+1] == '.'){
            return false;
        }
    }

    for (char i : strName){ // проверка на допустимые символы в имени 
        bool prov = false;
        for (char j : symbols){
            if (i == j){
                prov = true;
                break;
            }
        }
        if (prov == false){
            return false;
        }
    }

    if (strName[0]=='.' || strName[strName.size() -1]== '.'){  //проверка на то, что имя не начинается и не заканчивается на точку
        return false;
    }
    return true;
}

string normalEmail(const string& str){ // нормализируем, убираем всё после +, удаляем не нужные точки 
    size_t pos = str.find('@');
    string name = str.substr(0, pos);
    string domen = str.substr(pos);
    string cleanName = ""; // строка без точек

    size_t plusPos = name.find('+');
    if (plusPos != string::npos){ // считаем имя только до +
        name =name.substr(0, plusPos);
    }

    for (char c : name){ // удаляем все лишние точки 
        if (c != '.'){
            cleanName += c;
        }
    }

    return cleanName+domen;

}



int main(){
    string email;
    set<string> emails;
    bool limit = false;
    while (email!="end"){ // вводим email пока не введём end
        cin >> email; 
        if (limitations(email) == false && email !="end"){
            cout <<"ERROR!!!" <<endl;
        } else {
            if (email !="end"){
                email = normalEmail(email);
                emails.insert(email);
            }
        }
        
    }

    cout << "Уникальных адресов " << emails.size() << endl;

}