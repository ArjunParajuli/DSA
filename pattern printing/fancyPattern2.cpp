#include<iostream>
using namespace std;

int main(){
    int n=4;
   int count = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*i+1;j++){
            if(j%2 == 0){
                cout << count++;
            }else{
                cout << "*";
            }
        }
        cout << endl;
    }
    count = count - n;
    for(int i=0;i<n;i++){
        int k = count;
            for(int j=0;j<=n-i-1;j++){
                    cout << k; 
                    k++;
                if(j < n-i-1)
                 cout << "*";
            }
        count = count - (n-i-1);
        cout << endl;
    }

    return 0;
}