<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

/*
getline(cin, input);:
Reads a line of input from the standard input (cin) into the input string.

stringstream ss(input);:
Creates a stringstream object ss from the modified input string. stringstream is used to break down the input string by a delimiter (,)
into separate integer values.

while(getline(ss, inp, ',')){ ... }:
A loop that uses getline with the , (comma) delimiter to extract each integer (as a string) from the stringstream object ss. 
Each extracted string is stored in inp.

*/

vector<int> input_array_format() {
    vector<int> arr;
    string input;
    getline(cin, input);
    input = input.substr(1, input.size()-2);
    stringstream ss(input);
    string inp = "";
    while(getline(ss, inp, ',')){
        arr.push_back(stoi(inp));
    }
    
    return arr;
}

// 1 2 3 4 5
vector<int> input_space_separated(){
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);

    string elm = "";
    
    while(ss >> elm){
        arr.push_back(stoi(elm));
    }
    return arr;
}

// 1, 2, 3
vector<int> input_comma_separated(){
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string elm = "";
    while(getline(ss, elm, ',')){
        arr.push_back(stoi(elm));
    }
    
    return arr;
}

/* 
When number of elms is not given in input format in ques, we have to do cin till we get input
int main() {
    vector<int> arr;
    int num;
    while(cin >> num){
        arr.push_back(num);
    }
    for(auto i : arr)
        cout << i << " ";
    
    return 0;
}

stod("")

*/

/*
take the whole line in input string:-

    string s;
    getline(cin, s);

*/

/*
int main() {
    string data = "123 45.67 Hello";
    stringstream ss(data); // Create a stringstream object with the string `data`

    int integerPart;
    double doublePart;
    string wordPart;

    // Extract integer, double, and string from the stream
    ss >> integerPart >> doublePart >> wordPart;

    // Output the extracted values
    cout << "Integer: " << integerPart << endl;  // Output: Integer: 123
    cout << "Double: " << doublePart << endl;    // Output: Double: 45.67
    cout << "String: " << wordPart << endl;      // Output: String: Hello

    return 0;
}
*/

/*
int main() {
    vector<string> data = {"123 Hello 45.67", "1234 World 4.67"};

    vector<int> itr;
    vector<double> db;
    vector<string> str;

    for(auto elm : data){
        stringstream ss(elm);
        int i;
        double d;
        string w;
        ss >> i >> w >> d;
        itr.push_back(i);
        db.push_back(d);
        str.push_back(w);
    }

    for(auto i : itr) cout << i << " ";
    cout << endl;
    
    for(auto i : db) cout << i << " ";
    cout << endl; 
    
    for(auto i : str) cout << i << " ";
    cout << endl;

    return 0;
}
*/


int main() {
    // Case 1: [1,2,3,4,5]
    vector<int> arr1 = input_array_format();
    cout << " Case 1: [1,2,3,4,5]" << endl;
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;
}

=======
#include <bits/stdc++.h>
using namespace std;

/*
getline(cin, input);:
Reads a line of input from the standard input (cin) into the input string.

stringstream ss(input);:
Creates a stringstream object ss from the modified input string. stringstream is used to break down the input string by a delimiter (,)
into separate integer values.

while(getline(ss, inp, ',')){ ... }:
A loop that uses getline with the , (comma) delimiter to extract each integer (as a string) from the stringstream object ss. 
Each extracted string is stored in inp.

*/

vector<int> input_array_format() {
    vector<int> arr;
    string input;
    getline(cin, input);
    input = input.substr(1, input.size()-2);
    stringstream ss(input);
    string inp = "";
    while(getline(ss, inp, ',')){
        arr.push_back(stoi(inp));
    }
    
    return arr;
}

// 1 2 3 4 5
vector<int> input_space_separated(){
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);

    string elm = "";
    
    while(ss >> elm){
        arr.push_back(stoi(elm));
    }
    return arr;
}

// 1, 2, 3
vector<int> input_comma_separated(){
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string elm = "";
    while(getline(ss, elm, ',')){
        arr.push_back(stoi(elm));
    }
    
    return arr;
}

/* 
When number of elms is not given in input format in ques, we have to do cin till we get input
int main() {
    vector<int> arr;
    int num;
    while(cin >> num){
        arr.push_back(num);
    }
    for(auto i : arr)
        cout << i << " ";
    
    return 0;
}

stod("")

*/

/*
take the whole line in input string:-

    string s;
    getline(cin, s);

*/

/*
int main() {
    string data = "123 45.67 Hello";
    stringstream ss(data); // Create a stringstream object with the string `data`

    int integerPart;
    double doublePart;
    string wordPart;

    // Extract integer, double, and string from the stream
    ss >> integerPart >> doublePart >> wordPart;

    // Output the extracted values
    cout << "Integer: " << integerPart << endl;  // Output: Integer: 123
    cout << "Double: " << doublePart << endl;    // Output: Double: 45.67
    cout << "String: " << wordPart << endl;      // Output: String: Hello

    return 0;
}
*/

/*
int main() {
    vector<string> data = {"123 Hello 45.67", "1234 World 4.67"};

    vector<int> itr;
    vector<double> db;
    vector<string> str;

    for(auto elm : data){
        stringstream ss(elm);
        int i;
        double d;
        string w;
        ss >> i >> w >> d;
        itr.push_back(i);
        db.push_back(d);
        str.push_back(w);
    }

    for(auto i : itr) cout << i << " ";
    cout << endl;
    
    for(auto i : db) cout << i << " ";
    cout << endl; 
    
    for(auto i : str) cout << i << " ";
    cout << endl;

    return 0;
}
*/


int main() {
    // Case 1: [1,2,3,4,5]
    vector<int> arr1 = input_array_format();
    cout << " Case 1: [1,2,3,4,5]" << endl;
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;
}

>>>>>>> 8c82a314ca0fe9da5c6f415b4098b9c32392b4a4
