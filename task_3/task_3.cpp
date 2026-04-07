#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    int number;
    int kvad = 0; // количество чисел полные квадраты
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> number;
        int numSqrt = sqrt(number);
        if ( (numSqrt * numSqrt) == number){
            kvad +=1;
        }
    }
    cout << "Результат: " << kvad <<endl;
    return 0;
}