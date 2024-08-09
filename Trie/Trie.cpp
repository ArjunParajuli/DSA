#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Love babbar hashmaps & trie class 3

/*

Trie / multiway tree structure used to store a dynamic set of strings where the keys are usually strings. [can have multiple children and is used for pattern searching]

- Real life applicatoin: Autocomplete and Text Prediction.

- each node contains:
> a value(character) 
> its children which can be represented using array or hashmaps [each node has 26 children in array]
> mark if string is terminated here or not 

- insertion:
> if found among root's children, traverse
> if not found then insert and traverse

- search:
> check char wise, if found go further
> if not found, return

- deletion: [ no need to erase/remove string from trie as other are dependent on it ]
> jis string ko delete karna hai, uske last character par jakar usko isTerminal false mark kardo

*/

// using map for upper and lower chars: unordered_map<char, TrieNode*> children; 

class TrieNode{
public:
    char ch;
    TrieNode * children[26]; // array of pointers [The children array holds pointers to child nodes]
    // unordered_map<char, TrieNode*> children;  use when uppercase chars also included
    bool isTerminal;

    TrieNode(char ch){
        this->ch = ch;
        for(int i=0;i<26;i++){  // initialize all children to null
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};


    // insertion [ time: length of input word ]
    void insert(TrieNode * root, string word){
        // cout << "Inserting " << word[0] << endl;

        // base case [if every char of the word has been inserted]
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        char ch = word[0];  // start from the first char of input word
        int index = ch-'a'; // index where that char is to be inserted
        TrieNode * child; // create a node 

        // if found among the node's children, traverse
        if(root->children[index] != NULL){
            child = root->children[index]; // traverse
        }else{ // not found so create and traverse
            child = new TrieNode(ch); // create 
            root->children[index] = child; // insert
        }

        // recursion for further characters
        insert(child, word.substr(1)); // if original word was "arjun", now send "rjun" in next function call

    }

    
    // search [ time: length of input word ]
    bool searchString(TrieNode * root, string word){
        // base case [reached end so check if it is a terminal node or not]
        if(word.size() == 0){
            return root->isTerminal;
        }

        char ch = word[0];
        int index = ch-'a';
        TrieNode * child;

        // if present at its index then traverse further
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // not found
            return false;
        }

        // recursion for further search
        return searchString(child, word.substr(1));
    }

    // deletion [ time: length of input word ]
    void deleteString(TrieNode * root, string word){
        // base case [mark that string's last char's isTerminal false]
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        } 

        char ch = word[0];
        int index = ch-'a';
        TrieNode * child;
        // present
        if(root->children[index] != NULL){
            child = root->children[index]; // traverse
        }else{ // not present so return 
            return;
        }

        // recursion for further traversal
        deleteString(child, word.substr(1));
    }


    /*

    Q1) find Strings With given Prefix String:
        
    algo:
    - pehle traverse karke prefix k end char tak pohocho 
    - uske baad uske niche waley sarey string ko ans mai store karlo 

    */

    // ye func prefix k end char k niche waley strings ko store karta hai  
    // first tym par root mai lastChar hai so uske sarey children ko store karna hai
   void storeStrings(TrieNode * root, string &prefix, string &pre, vector<string> &ans){ 
    // base case [- don't return in base case bcoz the recursion stops automatically after the loop runs 26 times]
    if(root->isTerminal == true){
        // store
        ans.push_back(pre+prefix);   // pre ko pehle add karke karo kyuki prefix ka size 0 honey k baad storeStrings func call hua tha 
        // dont return bcoz uske niche vi chars hosakta hai
    }

    // jo bhi children hai uske liye recusrive call karke store karo 
    for(char ch='a';ch<='z';ch++){
        int index = ch-'a';
        TrieNode * next = root->children[index];
        if(next != NULL){
        // ye ek children hai, so store
            prefix.push_back(ch);
        // recursion for storing further
            storeStrings(next, prefix, pre, ans);
        // backtrack bcoz prefix taken by ref
            prefix.pop_back();
        }
    }
   }

    // ye func traverse karta hai prefix k end char tak
    void findStrWithPrefixStr(TrieNode * root, string prefix, string &pre, vector<string> &ans){  
        // base case [reached end of prefix char ]   
        if(prefix.size() == 0){   
            TrieNode * lastChar = root;  // if prefix="ar", then lastChar='r'
            storeStrings(lastChar, prefix, pre, ans); // 'r' k niche jitne bhi strings hai unko store karlo
            return;
        }

        // pick first char of prefix and check if that char exists as root's children, if yes traverse to its children
        char ch = prefix[0];
        int index = ch-'a';
        TrieNode * child;
        // char found
        if(root->children[index] != NULL){
            child = root->children[index]; // traverse to that prefix str
        }else{
            return; // no prefix found amoung any children
        }

        // recursion for further traversing
        findStrWithPrefixStr(child, prefix.substr(1), pre, ans);
    }
    // --- End of Q1


    /*
    
    Q2) create a Search suggestions system(leetcode). EG: prefix="arj" then "a", "ar", "arj" sab se start honey waley string find karo
    -> algo:
    - harek character ko end character manlo and store strings wala function call kardo
    */

    vector<vector<string>> findStrWithPrefixStr2(TrieNode * root, string prefix){  
        vector<vector<string>> ans;
        TrieNode * tempRoot=root;
        string pre = "";  // pre will be diff for each end char
        for(int i=0;i<prefix.size();i++){
            // take each char as last char and find if it exists as root's children or not
            char lastChar = prefix[i];
            int index = lastChar-'a';
            TrieNode * child = tempRoot->children[index];
            // lastchar exists as child
            if(child != NULL){
                pre.push_back(lastChar);
                vector<string> nicheKaAns;
                string dummy="";  // bcoz in storestring func was called when prefix was empty string
                storeStrings(child, dummy, pre, nicheKaAns);
                ans.push_back(nicheKaAns);

                // for next iteration (don't forget)
                tempRoot = child;
            }else{ // prefix's char not found among any children of root 
                break;
            }
        }
        return ans;
    }
// --- end of Q2


int main(){
    TrieNode * root = new TrieNode('#');
    insert(root, "arj");
    insert(root, "arjun");
    insert(root, "arun");
    insert(root, "parajuli");
    // string word = "arj";
    // searchString(root, word) ? cout << "found" : cout << "Not Found";
    // cout << endl;
    // deleteString(root, "arj");
    // searchString(root, word) ? cout << "found" : cout << "Not Found" << endl;

    // Q1
    // vector<string> ans;
    // string prefix = "ar";
    // string pre = prefix;
    // findStrWithPrefixStr2(root, prefix, pre, ans);
    // for(auto itr : ans)
    //     cout << itr << " ";

    // Q2
    string prefix = "arj";
    vector<vector<string>> ans = findStrWithPrefixStr2(root, prefix);
    for(int i=0;i<ans.size();i++){
        cout << prefix[i] << " as end char ->";
        for(auto itr:ans[i])
            cout << itr << " ";
        cout << endl;
    }


    return 0;
}

