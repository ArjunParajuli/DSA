#include<iostream>
using namespace std;

int main(){
    int n=5;
    int c;
    for(int i=1;i<=n;i++){
        c = 1;
        for(int j=1;j<=i;j++){
            cout << c << " ";
            c = c * (i-j)/j;
        }
        cout << endl;
    }


    return 0;
}