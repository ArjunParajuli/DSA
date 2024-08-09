#include <iostream>
using namespace std;

#define R 5
#define C 4

// Function to print wave
// Form for a given matrix
void wavePrint(int row, int col, int arr[R][C])
{
	// Loop to traverse matrix
	for (int j = 0; j < col; j++) {

		// If the current column
		// is even indexed, print
		// it in forward order
		if (j % 2 == 0) {
			for (int i = 0; i < row; i++) {
				cout << arr[i][j] << " ";
			}
		}

		// If the current column
		// is odd indexed, print
		// it in reverse order
		else {
			for (int i = row - 1; i >= 0; i--) {
				cout << arr[i][j] << " ";
			}
		}
	}
}

void wavePrint2(int row, int col, int arr[R][C]){
	for(int i=0;i<row;i++){
		if(i%2 == 0){
			for(int j=0;j<col;j++){
				cout << arr[i][j] << " ";
			}
		}else{
			for(int j=col-1;j>=0;j--){
				cout << arr[i][j] << " ";
			}
		}
	}
}

// Driver Code
int main()
{
	int arr[R][C] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 },
					{ 17, 18, 19, 20 } };

	wavePrint2(R, C, arr);

	return 0;
}
