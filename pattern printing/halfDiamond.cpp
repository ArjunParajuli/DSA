#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int condition;
    for(int i=0;i<2*n-1;i++){
        if(i<n){
            condition = i;
        }else{
            condition = n - (i%n) - 2; // i=5 then 5-(5%5)-2
        }
        for(int j=0;j<=condition;j++){
            cout << "*";
        }
           cout << endl;
    }

    return 0;
}