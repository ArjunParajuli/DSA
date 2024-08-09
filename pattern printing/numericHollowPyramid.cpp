

#include <iostream>

using namespace std;

int main()
{
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==0 || j==i || j==n-1){
                cout << j+1;
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
