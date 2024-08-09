

#include <iostream>

using namespace std;

int main()
{
    int n=10;
    int k = n;
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<k;j++){
            if(j<n-i-1)
                cout << " ";
            else if(j <= n-1){
               cout << ++c; 
            }else   
                cout << --c;
        }
        k++;
        cout << endl;
    }

    return 0;
}
